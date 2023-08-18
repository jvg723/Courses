clear all
close all
clc

delta_x=0.008;

y=-delta_x:0.0001:delta_x;



for i=1:length(y)
    u(i)=(3/2)*(abs(y(i))/delta_x)-(1/2)*(abs(y(i))/delta_x)^3;
    ydx(i)=y(i)/delta_x;

end

plot(u,ydx,'-k','linewidth',10)
set(gca,'FontSize',56,"FontName","Times");
x0=10;
y0=10;
width=1100;
height=800;
set(gcf,'position',[x0,y0,width,height]);
ylabel('$y/\delta(x)$','interpreter','latex')
xlabel('$u/U_{\infty}$','interpreter','latex')
title('x=0.2 m')