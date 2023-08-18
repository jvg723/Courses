function [p,u,v,us,vs,ps,p_old,u_old,v_old,S,As,An,Aw,Ae,Ap] = workArrays(nc,n,dxu,dys,dyv,dxs)

p = zeros(nc+2,nc+2);
u = zeros(nc+2,nc+2);
v = zeros(nc+2,nc+2);
us = u;
vs = v;
ps = p;
p_old = p;
u_old = u;
v_old = v;
S(1:n-1,1:n-1) = 0;

% Coefficients for poisson pressure equation
As = zeros(n,n);
As(:,3:n-1) = dxu/dys;
An = zeros(n,n);
An(:,2:n-2) = dxu/dys;
Aw = zeros(n,n);
Aw(3:n-1,:) = dyv/dxs;
Ae = zeros(n,n);
Ae(2:n-2,:) = dyv/dxs;
Ap = -(Aw + Ae + As + An);

end