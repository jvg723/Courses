function [ustar,u,vstar] = applyBC(imin,imax,jmin,jmax,u,ustar,utop,vstar)

%apply BC for u velocity
ustar(1,jmin:jmax)       = -ustar(2,1:jmax);    %left wall
ustar(imax+1,jmin:jmax)  = -ustar(imax,1:jmax); %right wall
ustar(imin:imax+1,1)     = 0.0;                 %bottom wall
ustar(imin:imax+1,jmax)  = utop;                %top wall 
u(imin:imax+1,jmax)      = utop;                %top wall

%apply BC for v velocity
vstar(1,1:jmax+1)        = 0.0;                 %left wall
vstar(imax,1:jmax+1)     = 0.0;                 %right wall
vstar(1:imax,1)          = -vstar(1:imax,2);    %bottom wall
vstar(1:imax,jmax+1)     = -vstar(1:imax,jmax); %top wall 

end