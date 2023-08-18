clear varaiables
close all
clc

%%% Input Parameters %%%

%Fluid Properties%
rho=1;      %Density
mu=1e-3;    %viscosity
Re=1000;    %Reynolds number
utop=1;     %u velocity at top of domain

%Geometry/Grid%
Lx=1;     %Length in x direction
Ly=1;     %Length in y direction
nx=20;    %Total number of cells in x direction
ny=20;    %Total number of cells in y direction

%Under relaxation parameters
alphaP=0.1;     %pressure under-relaxation
alphaVel=0.1;   %velocity under-relaxation

%Iteration criteria
tol=1e-5;       %Acceptable tolerance for residual
maxit=600;      %maximum number of iterations
maxRes=1000;    %Inital maximum residual
it=1;           %Iteration counter

%Solver iteration criteria
w=1;            %Relaxation scalar
maxitSOR=20;    %Maxmimum number of iterations
tolSOR=1e-5;    %Tolerance

%Time integration
dt=2e-2;         %Initial time step
tmax=0.2;        %Maximum time
nmax=tmax/dt;    %Maximum time steps
t=0;             %Time tracker

%%% Initalize the Problem %%%

%Grid cooridnates%
[imin,imax,jmin,jmax,x,y,dx,dxi,dy,dyi] = getGrid(nx,ny,Lx,Ly);

%Plot the mesh%
%plotGrid(x,y,dx,dy);

%Allcoate work arrays%
[u,ustar,uold,resu,du,v,vstar,vold,resv,dv,p,pstar,pprime,rhsp,divergence] = workArrays(imax,jmax);

%Apply Boundary Conditions%
ustar(imin:imax+1,jmax)  = utop;                %top wall 
u(imin:imax+1,jmax)      = utop;                %top wall

%%% Time Integration using Implicit Crank Nicholson %%%
while t<=tmax

    %%% Solve NS equation using simple algorithm %%%
    while ((it<= maxit) && (maxRes>tol))

        %solving u an v momentum equations for intermediate velocities%
        [ustar,du] = uMomentum(imin,imax,jmin,jmax,dx,dy,rho,mu,u,v,pstar,utop,alphaVel);
        [vstar,dv] = vMomentum(imin,imax,jmin,jmax,dx,dy,rho,mu,u,v,pstar,alphaVel);

        %Store old velocities%
        uold = u;
        vold = v;

        %Build the RHS vector of the Pressure Poisson matrix%
        [rhsp] = getRHS(imin,imax,jmin,jmax,dx,dy,rho,ustar,vstar);

        %Build the coefficent matrix for Pressure Poisson matrix%
        [Ap] = getAP(imin,imax,jmin,jmax,dx,dy,rho,du,dv);

        %Iterally solve the system of equations using an SOR solver%
        [solVec,err,iter,flag ] = sorSolver(Ap,rhsp,w,maxitSOR,tolSOR);

        %Solve for pressure correction and update pressure%
        [p,pprime] = corrPres(imin,imax,jmin,jmax,solVec,pstar,alphaP);

        %Update velocities base on pressure corrections%
        [u,v] = updateVelocity(imin,imax,jmin,jmax,ustar,vstar,pprime,du,dv,utop);

        %Check divergence of velocity field
        [divergence] = getDiv(imin,imax,jmin,jmax,dxi,dyi,u,v);

        %Use p as pstar on next iteration%
        pstar = p;

        %Find maximum residual in the domain%
        resu = abs(u-uold);
        resv = abs(v-vold);
        maxuRes = max(max(resu));
        maxvRes = max(max(resv));
        maxRes = max(maxuRes,maxvRes);

        %Check for convergence%
        disp(['it = ',int2str(it),'; Res = ',num2str(maxRes)])
        if (maxRes > 2)
            disp('not going to converge!');
            break;
        end

        %increment iteration counter
        it = it+1;

    end

    %Display countour at current time step
    disp(['Total Iterations = ',int2str(it-1)])
    figure
    contourf(x,y,u(2:imax,:)',50, 'edgecolor','none');colormap jet
    colorbar;
    axis([0 1 0 1]);
    title('steady Ux');

end

