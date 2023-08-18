function [imin,imax,jmin,jmax,x,y,dx,dxi,dy,dyi] = getGrid(nx,ny,Lx,Ly)
%function that builds a uniform rectilinear FV grid 

%Create Indicies in x and y directions
imin = 1;    %Index of first cell along x direciton
imax = nx;   %Index of last cell along x direction
jmin = 1;    %Index of first cell along y direciton
jmax = ny;   %Index of last cell along y direction

%Size of each cell
dx=Lx*1/(nx-1);					
dy=Ly*1/(ny-1); 

%Inverse of each cell
dxi = 1/dx;
dyi = 1/dy;

%Create grid coordinates
x=dx/2:dx:1-dx/2; 
y=0:dy:1; 

end