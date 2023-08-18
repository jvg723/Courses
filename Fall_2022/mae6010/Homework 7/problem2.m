clear all
close all
clc

[x,y] = meshgrid(-3:0.01:3);
m=1;
a=1;
U=1;
psi = U*y+(m/2*pi)*(atan2(y,x+a)-atan2(y,x-a));
psi2 = U*y-(m/2*pi)*(atan2(2*a*y,x^2+y^2-a^2));
figure(1)
contour(x,y,psi,[-5:0.5:5],'-k')
hold on
contour(x,y,psi2,[-5:0.5:5],'-r')
set(gca,'YTicklabel',[])
set(gca,'XTicklabel',[])
