function [imin,imax,jmin,jmax,x,y,xm,ym,dx,dy] = getGrid(Lx,Ly,nx,ny)

%Create Indicies in x and y directions
imin = 2;           %Location of left face of domain
imax = imin+nx-1;   %Location of right face of domain
jmin = 2;           %Location of bottom face of domain
jmax = jmin+ny-1;   %Location of top face of domain

%Create grid coordinates
x(imin:imax+1) = linspace(0,Lx,nx+1);
y(jmin:jmax+1) = linspace(0,Ly,ny+1);

%Mid points for the center of cells
xm(imin:imax) = 0.5*(x(imin:imax)+x(imin+1:imax+1));
ym(jmin:jmax) = 0.5*(y(jmin:jmax)+y(jmin+1:jmax+1));

%Size of each cell
dx = x(imin+1)-x(imin);
dy = y(jmin+1)-y(jmin);
dxi = 1/dx;
dyi = 1/dy;

end