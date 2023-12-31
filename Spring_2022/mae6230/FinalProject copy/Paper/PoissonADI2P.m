function [phi,res] = PoissonADI2P(phi,n,Ap,An,As,Ae,Aw,S,w)
%% Perform ADI
for j = 2:n-1
RHS1(2:n-1) = (1-w).*Ap(2:n-1,j).*phi(2:n-1,j) + w.*(-(An(2:n-1,j).*phi(2:n-1,j+1) + As(2:n-1,j).*phi(2:n-1,j-1))+ S(2:n-1,j));
phi(2:n-1,j) = Tri2(w.*Aw(2:n-1,j),Ap(2:n-1,j),w.*Ae(2:n-1,j),RHS1(2:n-1));
end
for i = 2:n-1
RHS2(2:n-1) = (1-w).*Ap(i,2:n-1).*phi(i,2:n-1) + w.*(-(Ae(i,2:n-1).*phi(i+1,2:n-1) ...
+ Aw(i,2:n-1).*phi(i-1,2:n-1)) + S(i,2:n-1));
phi(i,2:n-1) = Tri2(w.*As(i,2:n-1),Ap(i,2:n-1),w.*An(i,2:n-1),RHS2(2:n-1));
end
%% Find Residual
rho(2:n-1,2:n-1) = S(2:n-1,2:n-1) ...
- ( Ap(2:n-1,2:n-1).*phi(2:n-1,2:n-1) ...
+ An(2:n-1,2:n-1).*phi(2:n-1,3:n) ...
+ As(2:n-1,2:n-1).*phi(2:n-1,1:n-2) ...
+ Ae(2:n-1,2:n-1).*phi(3:n,2:n-1) ...
+ Aw(2:n-1,2:n-1).*phi(1:n-2,2:n-1));
res = sqrt(sum(sum(rho.^2))/n);

end