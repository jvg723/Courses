clear varaiables
close all
clc

%%% Input Parameters %%%

%Fluid Properties%
rho=1;      %Density
mu=1e-3;    %viscosity
Re=100;     %Reynolds number
Ulid=1;     %u velocity at top of domain

%Geometry/Grid%
nc=50;
n=nc+2;
L=1;
nx=nc;
ny=nc;

%Time integration
tmax=5;
dt=0.000125;

%Iteration criteria
ipmax = 5000;
iter.p = 2;
iter.o = 1;
res.p(1) = 0;
tp = 0;

%Computing time
wt0 = cputime;

%Relation variable
w = 1.1;

%Update for printing to screen
update = 100;

%%% Initalize the Problem %%%

%Grid properties%
[hx,hy,delta,dxu,dxs,dyv,dys,x,y,tstring,X,Y] = getGrid(nx,ny,nc,L,Re);

%Allcoate work arrays%
[p,u,v,us,vs,ps,p_old,u_old,v_old,S,As,An,Aw,Ae,Ap] = workArrays(nc,n,dxu,dys,dyv,dxs);

%%% Time Advacement %%%
for t = 0:dt:tmax

    %Apply Boundary Conditions%
    [u,v] = applyBC(u,v,Ulid);

    %Build H matrix to store diffusive and connective terms%
    [Hx,Hy] = buildH(u,v,dxu,dxs,dyv,dys,Re);

    %solving u an v momentum equations for intermediate velocities%
    [us,vs] = getIntVel(n,u,v,dt,Hx,Hy,iter);

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
    if err.u(iter.o) < 1E-8 && err.v(iter.o) < 1E-8
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