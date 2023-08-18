function [hx,hy,delta,dxu,dxs,dyv,dys,x,y,tstring,X,Y] = getGrid(nx,ny,nc,L,Re)
%function that builds a uniform rectilinear FV grid 

%Cell size
hx = 1/nx;
hy = 1/ny;

%Cell spacing
delta = L/nc;
dxu = delta;
dxs = delta;
dyv = delta;
dys = delta;


% constant grid spacing
x = 0:1/(nc-1):1;
y = 0:1/(nc-1):1;

%Create mesh grid
[X,Y] = meshgrid(x,y);

%string to display during iterations
tstring = ['Re = ', num2str(Re),', Number of cells = ', num2str(nc),'x',num2str(nc)];

end