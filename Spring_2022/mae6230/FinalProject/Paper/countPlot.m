% uc = 0.5*(u(2:end-1,2:end-1) + u(3:end,2:end-1));
% vc = 0.5*(v(2:end-1,2:end-1) + v(2:end-1,3:end));
% figure(1)
% uu = sqrt(u.^2 + v.^2);
% contourf(X,Y,uu(2:end-1,2:end-1)',50)
% %colormap summer
% c = colorbar;
% %colormap winter
% c.Location = 'southoutside';
% caxis([0, 1]);
% h = streamslice(X,Y,uc',vc',2);
% set( h, 'Color', [1 1 1] )
% axis([0,L,0,L])
% title(['Re=',num2str(Re)])
% xlabel('{\it x}','fontsize',24,'FontName','Times')
% ylabel('{\it y}','fontsize',24,'FontName','Times')
% ax = gca;
% ax.FontSize = 24;
% ax.FontName = 'Times';
% x0=10;
% y0=10;
% width=850;
% height=1100;
% set(gcf,'position',[x0,y0,width,height])

figure(2)
contourf(X,Y,p(2:end-1,2:end-1)',50)
c = colorbar;
%colormap winter
c.Location = 'southoutside';
caxis([-0.05, 0.05]);
axis([0,L,0,L])
title(['Re=',num2str(Re)])
xlabel('{\it x}','fontsize',24,'FontName','Times')
ylabel('{\it y}','fontsize',24,'FontName','Times')
ax = gca;
ax.FontSize = 24;
ax.FontName = 'Times';
x0=10;
y0=10;
width=850;
height=1100;
set(gcf,'position',[x0,y0,width,height])