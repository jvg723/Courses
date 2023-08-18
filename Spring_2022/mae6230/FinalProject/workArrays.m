function [u,ustar,uold,resu,du,v,vstar,vold,resv,dv,p,pstar,pprime,rhsp,divergence] = workArrays(imax,jmax)

%u velocity arrays
u      = zeros(imax+1,jmax);    %final u velocity 
ustar  = zeros(imax+1,jmax);    %intermediate u velocity
uold   = zeros(imax+1,jmax);    %old u velocity
resu   = zeros(imax+1,jmax);    %residual u velocity
du     = zeros(imax+1,jmax);    %u velocity orrection coefficient

%v velocity arrays
v      = zeros(imax,jmax+1);    %final v velocity 
vstar  = zeros(imax,jmax+1);    %intermediate v velocity 
vold   = zeros(imax,jmax+1);    %old v velocity
resv   = zeros(imax,jmax+1);    %residual v velocity
dv     = zeros(imax,jmax+1);    %v velocity orrection coefficient

%pressure arrays
p       = zeros(imax,jmax);     %final pressure
pstar   = zeros(imax,jmax);     %intermediate pressure
pprime  = zeros(imax,jmax);     %pressure correction 
rhsp    = zeros(imax,jmax);     %RHS vector of pressure correction equation

%Array for checking divergence 
divergence = zeros(imax,jmax); 

end