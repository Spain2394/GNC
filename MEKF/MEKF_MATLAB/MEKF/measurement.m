function [y,C] = measurement(q,rN)

QBN = qtodcm(q)';

rB = QBN*rN;

C = zeros(3*size(rN,2),6);

for k = 1:size(rN,2)
    C(3*(k-1)+(1:3),:) = [hat(rB(:,k)), zeros(3)];
end

C = [eye(3), zeros(3); C];

y = [q; rB(:)];


end

