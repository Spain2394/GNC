/*
 * Author: Nick Goodson 
 * Jan 15th 2020
 *
*/

#include "iLQRsimple.h"
// #include "../../pybind11/include/pybind11/pybind11.h"
// #include "../../pybind11/include/pybind11/eigen.h"
// namespace py = pybind11;
using namespace Eigen;
using namespace std;

#define MAX_ITERS 1000

/**
  * Simple iLQR implementation
  *
  */
bool iLQRsimple(MatrixXd& x0, 
				MatrixXd& xg,  
				MatrixXd& Q, 
				MatrixXd& R, 
				MatrixXd& Qf, 
				double dt, 
				double tol,
				MatrixXd& xtraj,
				MatrixXd& utraj,
				MatrixXd& K,
				vector<double>& Jhist) {


	int success_flag = true;  // Returns true if algorithm converged

	// Define sizes
	unsigned int Nx = static_cast<unsigned int>( x0.rows() );
	unsigned int Nu = static_cast<unsigned int>( utraj.rows() );
	unsigned int N = static_cast<unsigned int>( xtraj.cols() );

	MatrixXd A = MatrixXd::Zero(Nx, Nx * (N-1));
	MatrixXd B = MatrixXd::Zero(Nx, Nu * (N-1));


	// Forward simulate with initial controls utraj0
	double J = 0;
	for ( int k = 0; k < N-1; k++ ) {

		J = J + (0.5*((xtraj(all, k) - xg).transpose()) * Q * (xtraj(all, k) - xg) + 0.5*(utraj(all, k).transpose()) * R * utraj(all, k))(0);
		rkstep(utraj(all, k), dt, k, xtraj, A, B);

		// NOTE: Passing a slice of a matrix by non-const reference (eg. xtraj(all, k+1)) does not compile.
		// Have to pass the entire matrix (by ref) and pass in the step 'k' so the function can assign to the slice directly
		// rkstep(xtraj(all, k), utraj(all, k), dt, xtraj(all, k+1), A(all, seq(Nx*k, Nx*(k+1)-1)), B(all, seq(Nu*k, Nu*(k+1)-1)));
	}

	J = J + (0.5*((xtraj(all, N) - xg).transpose()) * Qf * ((xtraj(all, N) - xg)))(0); 	// Add terminal cost
	Jhist[0] = J;


	// Intialize matrices for optimisation
	MatrixXd S = MatrixXd::Zero(Nx, Nx);
	MatrixXd s = MatrixXd::Zero(Nx, 1);
	MatrixXd l = MatrixXd::Constant(Nu, N, 1 + tol);
	MatrixXd q(Nx, 1);
	MatrixXd r(Nu, 1);

	MatrixXd Snew = S; // temporary matrices for update step
	MatrixXd snew = s;
	MatrixXd Ak(Nx, Nx);
	MatrixXd Bk(Nx, Nu);
	MatrixXd Kk(Nu, Nx);
	MatrixXd LH(Nu, Nu);

	// Line search temp matrices and params
	MatrixXd xnew = MatrixXd::Zero(Nx, N);
	MatrixXd unew = MatrixXd::Zero(Nu, N-1);
	double alpha;
	double Jnew;

	int iter = 0;
	while ( l.lpNorm<Infinity>() > tol) {

		iter += 1;
		if (iter > MAX_ITERS):
			// Break from the loop and don't perform the maneuver
			success_flag = false;
			return success_flag;

		// Initialize backwards pass
		S << Qf;
		s << Qf*(xtraj(all, N) - xg);
		for ( int k = (N-1); k >= 0; k-- ) {

			// Calculate cost gradients (for this time step)
			q = Q * (xtraj(all, k) - xg);
			r = R * utraj(all, k);

			// Calculate feed-forward correction and feedback gain
			// Need to check that these assignments don't assign on heap/use too much memory (Alternative code at botoom of file)
			Ak = A(all, seq(Nx*k, Nx*(k+1)-1));
			Bk = B(all, seq(Nu*k, Nu*(k+1)-1));
			
			// Cholesky
			LH = (R + Bk.transpose()*S*Bk);
			l(all, k) = LH.llt().solve((r + Bk.transpose()*s));
			K(all, seq(Nx*k, Nx*(k+1)-1)) = LH.llt().solve(Bk.transpose()*S*Ak);

			// Calculate new cost to go matrices (Sk, sk)
			Kk = K(all, seq(Nx*k, Nx*(k+1)-1));
			Snew = Q + Kk.transpose()*R*Kk + (Ak - Bk*Kk).transpose()*S*(Ak - Bk*Kk);
			snew = q - Kk.transpose()*R + Kk.transpose()*R*l(all, k) + (Ak - Bk*Kk).transpose()*(s - S*Bk*l(all, k));
			S = Snew;
			s = snew;
		}

		// Forward pass line search with new l and K
		xnew(all, 0) = xtraj(all, 0);
		Jnew = J + 1;
		alpha = 1;

		while ( Jnew > J ) {
			Jnew = 0;
			for ( int k = 0; k < N; k++ ) {
				unew(all, k) = utraj(all, k) - alpha*l(all, k) - K(all, seq(Nx*k, Nx*(k+1)-1))*(xnew(all, k) - xtraj(all, k));

				// rkstep(xnew(all, k), unew(all, k), dt, xnew(all, k+1), A(all, seq(Nx*k, Nx*(k+1)-1)), B(all, seq(Nu*k, Nu*(k+1)-1)));
				rkstep(unew(all, k), dt, k, xnew, A, B);

				J = J + (0.5*((xnew(all, k) - xg).transpose())*Q*(xnew(all, k) - xg) + 0.5*(unew(all, k).transpose())*R*unew(all, k))(0);
			}
			J = J + (0.5*((xtraj(all, N) - xg).transpose()) * Qf * ((xtraj(all, N) - xg)))(0);
			alpha *= 0.5;
		}
		
		xtraj = xnew; // Make sure this assigns to the reference as desired
		utraj = unew;
		J = Jnew;
		Jhist[iter] = J;
	}

	return success_flag;
}


/**
  * Performs a single midpoint (2nd order Runge-Kutta) step
  * Can modify this function to include the satellites dynamics
  * in the final implemenation to prevent having to pass matrices to a dynamics function
  *
  */
// void rkstep(const MatrixXd& x0, const MatrixXd& u0, double dt, int k, MatrixXd& x1, MatrixXd& A, MatrixXd& B) {
void rkstep(const MatrixXd& u0, double dt, int k, MatrixXd& xtraj, MatrixXd& A, MatrixXd& B) {

	// Define sizes (hard code in final version)
	unsigned int Nx = static_cast<unsigned int>( xtraj.rows() );
	unsigned int Nu = static_cast<unsigned int>( u0.rows() );

	// Extract current state
	MatrixXd x0 = xtraj(all, k);

	// Initialize matrices to pass to dynamics
	// In final iplemenation, the size of these matrices should be specified
	MatrixXd xdot1(Nx, 1), xdot2(Nx, 1);
	MatrixXd dxdot1(Nx, Nx+Nu), dxdot2(Nx, Nx+Nu);  // [A B]

	//Initialize matrices for RK midpoint step
	MatrixXd A1, A2;
	MatrixXd B1, B2;

	// Step Dynamics (update xtraj, A and B at timestep k+1)
	pendulumDynamics(0, x0, u0, xdot1, dxdot1);
	pendulumDynamics(0, x0 + dt*0.5*xdot1, u0, xdot2, dxdot2);
	xtraj(all, k+1) = x0 + dt * xdot2;

	A1 = dxdot1(all, seq(0, Nx));
	A2 = dxdot2(all, seq(0, Nx));

	B1 = dxdot1(all, seq(Nx+1, Nx+Nu));
	B2 = dxdot2(all, seq(Nx+1, Nx+Nu));

	A(all, seq(Nx*k, Nx*(k+1)-1)) = MatrixXd::Identity(Nx, Nx) + dt*A2 + 0.5*dt*dt*A2*A1;
	B(all, seq(Nu*k, Nu*(k+1)-1)) = dt*B2 + 0.5*dt*dt*A2*B1;

}

/*
PYBIND11_MODULE(iLQR_SIMPLE_cpp, m) {
	m.doc() = "iLQR main functions for simple dynamical systems"; // optional module docstring
	m.def("iLQRsimple", &iLQRsimple, "Calcualte an optimal trajectory using iLQR");
	m.def("rkstep", &rkstep, "performs a runge-kutta update step on the non-linear and linearized system");
}
*/


/*
			// This code is less readable than assigning Ak, Bk, Kk as new MatrixXd variables from A, B, K
			// but indexing should be more compuationally efficient.
			int bIdxStrt = Nu * k 
			int bIdxEnd = Nu * k + Nu -1;
			int aIdxStrt = Nx * k;
			int aIdxEnd = Nx * k + Nx -1;

			MatrixXd LH = (R + B(all, seq(bIdxStrt, bIdxEnd)).transpose()*S*B(all, seq(bIdxStrt, bIdxEnd)));
			MatrixXd l_RH = (r + B(all, seq(bIdxStrt, bIdxEnd)).transpose()*s);
			MatrixXd K_RH = (B(all, seq(bIdxStrt, bIdxEnd)).transpose()*S*A(all, seq(aIdxStrt, aIdxEnd)));

			l(all, k) = LH.colPivHouseholderQr().solve(l_RH);  // Use solver to perform inversion
			K(all, seq(aIdxStrt, aIdxEnd)) = LH.colPivHouseholderQr().solve(K_RH); // K has same columns as A matrix

			// Calculate new cost to go matrices (Sk, sk)
			Snew = Q + K(all, seq(aIdxStrt, aIdxEnd)).transpose()*R*K(all, seq(aIdxStrt, aIdxEnd)) + 
					(A(all, seq(aIdxStrt, aIdxEnd)) - B(all, seq(bIdxStrt, bIdxEnd))*K(all, seq(aIdxStrt, aIdxEnd).transpose()) *
					S*((A(all, seq(aIdxStrt, aIdxEnd)) - B(all, seq(bIdxStrt, bIdxEnd))*K(all, seq(aIdxStrt, aIdxEnd));

*/