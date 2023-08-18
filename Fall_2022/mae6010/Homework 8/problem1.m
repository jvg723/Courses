clear all
close all
clc

syms A omega k t H x y

u(x,y)=(A*omega*sin(k*x-omega*t)*cosh(k*(y+H)))/sinh(k*H);
v(x,y)=(-A*omega*cos(k*x-omega*t)*sinh(k*(y+H)))/sinh(k*H);

U=[u v];

dudy=diff(u,y);
dvdx=diff(v,x);
% 
% phi1=int(u,x)
phi=int(v,y)%+int(v,y,[-H 0])
phi=int(u,x)

% phi2
% diff(z,x)