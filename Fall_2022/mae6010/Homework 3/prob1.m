clear all
close all
clc

syms dxi Ui Ui1

div_x=[-dxi dxi];
U=[Ui Ui1];

y=div_x.*U

sum(y)

% h=1;
% U=5;
% syms r x
% 
% u=(-12*U*r/h)*(x/h-x^2/h^2)+(12*U/h)*(x^2/2*h-x^3/3*h^2)-U
% 
% g=gradient(u,[r,x])
% 
% [R, X] = meshgrid(-1:.1:1,-1:.1:1);
% G1 = subs(g(1),[r x],{R,X});
% G2 = subs(g(2),[r x],{R,X});
% quiver(R,X,G1,G2,'LineWidth',3)
% 
% ylim([0 1])
% xlim([-1 1.0])
% 
% ylabel('x')
% xlabel('r')
% 
% set(gca,'FontSize',24,"FontName","Times")
% 
% x0=10;
% y0=10;
% width=1100;
% height=800;
% set(gcf,'position',[x0,y0,width,height])