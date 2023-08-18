% INPUTS

% Re Reynolds number
% dt Timestep size(s)
% w Over-relaxation factor
% nc Number of finite volume (area) cells
% update Update Heads Up Display (HUD) every x timesteps
% tmax Maximum solution time
% ipmax Maximum inner iterations to solve the Poisson pressure eq.

clc
clear all
close all

wt0 = cputime;
Re = 500;
dt = 0.00015;
w = 1.1;
nc = 120;
update = 100;
tmax = 1000;
ipmax = 5000;
tol = 1e-6;
Ulid = 1;
n = nc+2;
L = 1;
nx = nc;
ny = nc;
hx = 1/nx;
hy = 1/ny;
delta = L/nc;
dxu = delta;dxs = delta;dyv = delta;dys = delta;
% constant grid spacing
x = 0:1/(nc-1):1;
y = 0:1/(nc-1):1;
% x(1:nx+1)=(0:nx);
% y(1:ny+1)=(0:ny);
[X,Y] = meshgrid(x,y);
tstring = ['Re = ', num2str(Re),', Number of cells = ', num2str(nc),'x',num2str(nc)];

%% Initialize the solution
% points used:
% scalar/pressure
% i = 2:(nc+2)-1
% j = 2:(nc+2)-1
% x-momentum
% i = 3:(nc+2)-1
% j = 2:(nc+2)-1
% y-momentum
% i = 2:(nc+2)-1
% j = 3:(nc+2)-1
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

%% Solution

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
iter.p = 2;
iter.o = 1;
res.p(1) = 0;
tp = 0;
for t = 0:dt:tmax
    % PREDICTOR
    [u,v] = setBCs(u,v,Ulid);
    [Hx,Hy] = HHP(u,v,dxu,dxs,dyv,dys,Re);
    if iter.o == 1
        us(2:n-1,1:n-1) = u(2:n-1,1:n-1) + dt*Hx(2:n-1,1:n-1);
        vs(1:n-1,2:n-1) = v(1:n-1,2:n-1) + dt*Hy(1:n-1,2:n-1);
    else
        [Hx_old,Hy_old] = HHP(u_old,v_old,dxu,dxs,dyv,dys,Re);
        us(2:n-1,1:n-1) = u(2:n-1,1:n-1) + dt/2*(3*Hx(2:n-1,1:n-1) - Hx_old(2:n-1,1:n-1));
        vs(1:n-1,2:n-1) = v(1:n-1,2:n-1) + dt/2*(3*Hy(1:n-1,2:n-1) - Hy_old(1:n-1,2:n-1));
    end
    u_tp = us;
    v_tp = vs;
    % CORRECTOR
    for i = 2:n-1
        for j = 2:n-1
            S(i,j) = 1/dt*((us(i+1,j) - us(i,j))*dyv + (vs(i,j+1) - vs(i,j))*dxu);
        end
    end
    tpp = cputime;
    for c = 1:ipmax
        iter.p = iter.p + 1;
        [p,res.p(iter.p)] = PoissonADI2P(p,n,Ap,An,As,Ae,Aw,S,w);
        if res.p(iter.p) < 1e-5
            break
        elseif isnan(res.p(iter.p)) == 1
            disp('SOLUTION DIVERGED')
            beep
            return
        end
    end
    if c == ipmax
        disp('Warning: Pressure unconverged')
        disp((res.p(iter.p)))
    end
    tp = tp + (cputime - tpp);

    % CORRECTION
    u(2:n-1,2:n-1) = us(2:n-1,2:n-1) - dt/dxs*(p(2:n-1,2:n-1) - p(1:n-2,2:n-1));
    v(2:n-1,2:n-1) = vs(2:n-1,2:n-1) - dt/dys*(p(2:n-1,2:n-1) - p(2:n-1,1:n-2));
    err.p(iter.o) = norm(p - p_old);
    err.u(iter.o) = norm(u - u_old);
    err.v(iter.o) = norm(v - v_old);
    if err.u(iter.o) < tol && err.v(iter.o) < tol
        beep
        wt = cputime - wt0;
        break
    end
    p = p - p(5,5); % normalize pressure
    p_old = p;
    u_old = u;
    v_old = v;
    % Heads-up display
    if rem(t,dt*update) == 0 && t ~= 0
        HUD(t,wt0,iter,err,tstring)
        disp(tp)
    end
    iter.o = iter.o + 1;
end

uc = 0.5*(u(2:end-1,2:end-1) + u(3:end,2:end-1));
vc = 0.5*(v(2:end-1,2:end-1) + v(2:end-1,3:end));
figure(2)
uu = sqrt(u.^2 + v.^2);
contourf(X,Y,uu(2:end-1,2:end-1)',20)
streamslice(X,Y,uc',vc',2)
axis([0,L,0,L])
title(['Lid Driven Cavity Error, ',tstring])
xlabel('X/L')
ylabel('Y/L')
wt = cputime - wt0;
fname =['Re',num2str(Re),'nc',num2str(nc),'dt',num2str(dt)];
fname = strrep(fname,'.','p');
save(fname)