function [x,u,K,Jhist,result] = iLQR(DYNAMICS, COST, x0, xg, u0, u_lims, Ops)
% Solves finite horizon optimal control problem using the iterative
% linear quadratic redualtor method

% Note that this solver will not work without control limits

% Inputs
% ===========================================
% DYNAMICS - Function handle for the rkstep/ dynamics update
%           (In final implementation remove this and just put dynamcis
%           and cost functions at bottom of this file)
%
% COST - Function handle for cost calculation/ cost derivatives
%
% x0 - The intial trajectory (n, N)
%
% xg - The goal state (n, 1)
%
% u0 - The initial control sequeunce (m, N-1)
%
% u_lims - The control limits (m, 2) (lower, upper)
%
% Ops (options):
% -----------------------
% dt, max_iters, exit_tol, grad_tol, lambda_tol, z_min, lambda_max, lambda_min,
% lambda_scaling


% Outputs
% ===========================================
% x - Final nominal trajectory (n, N)
%
% u - Final open-loop controls (m, N-1)
%
% K - Feedback control gains (n, m, N-1)
%
% Jhist - The cost history (convergence)


% CONSTANTS
Alphas = 10.^linspace(0, -3, 11);  % line search param
lambda = 1;
dlambda = 1;
N = size(u0, 2) + 1;
Nx = size(x0, 1);
Nu = size(u0, 1);


% Initial Forward rollout
% Returns xtraj, (unew=utraj0), cost
l = zeros(Nu, N-1);
K = zeros(Nu, Nx, N-1);
alpha = 0;
[x,u,fx,fu,cx,cu,cxx,cuu,cost] = forwardRollout(DYNAMICS,COST,x0,xg,u0,l,K,alpha,u_lims,Ops.dt);
Jhist = [];
Jhist(1) = cost;


% Convergence check params
expectedChange = 0; % Expected cost change
z = 0;              % Ratio of cost change to expected cost change

fprintf("\n==================Begin iLQR================\n");
for iter = 1:Ops.max_iters
    fprintf("\n---New Iteration---\n");
    
    % Backward Pass
    %=======================================
    backPassDone = 0;
    while ~backPassDone
        [l,K,dV,diverge] = backwardPass(fx,fu,cx,cu,cxx,cuu,lambda,u_lims,u);
        
        if diverge
            fprintf("---Cholesky factorizaton failed at timestep %d---\n",diverge);
            
            % Increase regularization parameter (lambda)
            dlambda = max(Ops.lambda_scaling * dlambda, Ops.lambda_scaling);
            lambda = max(lambda * dlambda, Ops.lambda_min);
            if lambda > Ops.lambda_max
                break;
            end
            continue;  % Retry with larger lambda
        end
        backPassDone = 1;
    end
    
    % Check gradient of control, defined as l/u
    % Terminate if sufficiently small (success)
    g_norm = mean(max(abs(l)./(abs(u)+1),[],1)); % Avg of max grad at each time step
    if g_norm < Ops.grad_tol && lambda < Ops.lambda_tol
        result = 1;
        fprintf("\n---Success: Gradient decreased below grad_tol---\n");
        break;
    end
   
    % Forward Line-Search
    %===========================================
    fwdPassDone = 0;
    if backPassDone
        for alpha = Alphas
            [x_n,u_n,fx_n,fu_n,cx_n,cu_n,cxx_n,cuu_n,cost_n] = forwardRollout(DYNAMICS,COST,x,xg,u,l,K,alpha,u_lims,Ops.dt);
            expectedChange = -alpha*(dV(1) + alpha*dV(2));
            if expectedChange > 0
                z = (cost - cost_n)/expectedChange;
            else
                z = sign(cost - cost_n);
                fprintf("\n---Warning: non positive expected reduction---\n");
            end
            if z > Ops.z_min
                fwdPassDone = 1;
                break;
            end
        end
    end
    
    % Parameter Updates
    %=============================================
    if fwdPassDone
        % Decrease Lambda
        dlambda = min(dlambda/Ops.lambda_scaling, 1/Ops.lambda_scaling);
        lambda = lambda * dlambda * (lambda > Ops.lambda_min);  % set = 0 if lambda too small
        dcost = cost - cost_n;
        
        % Update trajectory and controls
        x = x_n;
        u = u_n;
        fx = fx_n;
        fu = fu_n;
        cx = cx_n;
        cu = cu_n;
        cxx = cxx_n;
        cuu = cuu_n;
        cost = cost_n;
        Jhist(iter+1) = cost;
        
        % Terminate ?
        if dcost < Ops.exit_tol
            result = 1;
            fprintf('\n---Success cost change < tolerance---\n');
            break;
        end
        
    else
        % No cost reduction (based on z-value)
        % Increase lambda
        dlambda = max(Ops.lambda_scaling * dlambda, Ops.lambda_scaling);
        lambda = max(lambda * dlambda, Ops.lambda_min);
        
        if lambda > Ops.lambda_max
            % Lambda too large - solver diverged
            result = 0;
            fprintf("\n---Diverged: new lambda > lambda_max---\n");
            break;
        end
        
    end

end

if iter == Ops.max_iters
    % Ddin't converge completely
    result = 0;
    fprintf("\n---Warning: Max iterations exceeded---\n");
end
    
end

function [xnew,unew,fx,fu,cx,cu,cxx,cuu,cost] = forwardRollout(DYNAMICS,COST,x,xg,u,l,K,alpha,u_lims,dt)
% Uses an rk method to roll out a trajectory
% Returns the new trajectory, cost and the derivatives along the trajectory

% If feed-forward and feed-back controls l, K are non-zero
% then the unew returned is the new control sequeunce. Otherwise unew = u

% Sizes
N = size(x,2);
Nx = size(x,1);
Nu = size(u,1);

% Initialize outputs
xnew = zeros(Nx,N);
unew = zeros(Nu,N-1);
fx = zeros(Nx,Nx,N-1);
fu = zeros(Nx,Nu,N-1);
cx = zeros(Nx,N);
cu = zeros(Nu,N-1);
cxx = zeros(Nx,Nx,N);
cuu = zeros(Nu,Nu,N-1);
cost = 0;

xnew(:,1) = x(:,1);
terminal = 0;
for k = 1:(N-1)
    
    % Update the control during line-search
    % (During inital forward rollout, l and K will be arrays of zeros)
    unew(:,k) = u(:,k) - alpha*l(:,k) - K(:,:,k)*(xnew(:,k) - x(:,k));

    % Ensure control is within limits
    unew(:,k) = min(u_lims(:,2), max(u_lims(:,1), unew(:,k)));

    % Step the dynamics forward
    [xnew(:,k+1),fx(:,:,k),fu(:,:,k)] = DYNAMICS(xnew(:,k), unew(:,k), dt);
    
    % Calculate the cost
    [c, cx(:,k),cu(:,k), cxx(:,:,k), cuu(:,:,k)] = COST(xnew(:,k), xg, unew(:,k), terminal); 
    cost = cost + c;
end

% Final cost
terminal = 1;
u_temp = zeros(Nu,1);
[c,cx(:,N),~,cxx(:,:,N),~] = COST(xnew(:,N), xg, u_temp, terminal); 
cost = cost + c;

function [x_skew] = skew_mat(x)
% Returns skew symmetric - cross porduct matrix of a vector

x_skew = [0 -x(3) x(2); x(3) 0 -x(1); -x(2) x(1) 0];

end
end


function [l, K, dV, diverge] = backwardPass(fx,fu,cx,cu,cxx,cuu,lambda,u_lims,u)
% Perfoms the LQR backward pass to find the optimal controls
% Solves a quadratic program (QP) at each timestep for the optimal
% controls given the control limits

N = size(u, 2) + 1;
Nx = size(fx,1);
Nu = size(u,1);

% Initialize matrices (for C)
l = zeros(Nu,N-1);
K = zeros(Nu,Nx,N-1);
Qx = zeros(Nx,1);
Qu = zeros(Nu,1);
Qxx = zeros(Nx,Nx);
Quu = zeros(Nu,Nu);
Qux = zeros(Nu,Nx);

Kk = zeros(Nu,Nx);
result = 0;

% Change in cost
dV = [0 0];

% Set cost-to-go Jacobain and Hessian equal to final costs
Vx = cx(:, N);
Vxx = cxx(:,:,N);

diverge = 0;
for k=(N-1):-1:1
    
    % Define cost gradients
    Qx = cx(:,k) + fx(:,:,k)'*Vx;
    Qu = cu(:,k) + fu(:,:,k)'*Vx;
    Qxx = cxx(:,:,k) + fx(:,:,k)'*Vxx*fx(:,:,k);
    Quu = cuu(:,:,k) + fu(:,:,k)'*Vxx*fu(:,:,k);
    Qux = fu(:,:,k)'*Vxx*fx(:,:,k);
    
    % Regularization (for Cholesky positive definiteness)
    QuuF = Quu + eye(Nu)*lambda;
    
    % Solve the Quadratic program with control limits
    upper = u_lims(:,2) - u(:,k);
    lower = u_lims(:,1) - u(:,k);
    l_idx = min(N-1, k+1);
    [lk,result,Luu,free] = boxQPsolve(QuuF,Qu,lower,upper,-1*l(:,l_idx));

    if result < 1
        diverge = k;
        return;
    end
    
    % Solve for feedback gains in non-clamped rows of u
    % (using cholesky factor of Quu)
    Kk(:,:) = 0;
    if any(free)
        Kk(free, :) = -Luu\(Luu'\Qux(free,:));
    end
    
    % Update Cost to Go
    dV  = dV + [lk'*Qu  (1/2)*lk'*Quu*lk];
    Vx  = Qx  + Kk'*Quu*lk + Kk'*Qu  + Qux'*lk;
    Vxx = Qxx + Kk'*Quu*Kk + Kk'*Qux + Qux'*Kk;
    Vxx = (1/2)*(Vxx + Vxx');  % Make sure Hessian is symmetric
    
    % Update Control Vectors
    l(:, k) = -lk;
    K(:,:,k) = -Kk;
    
end

end



