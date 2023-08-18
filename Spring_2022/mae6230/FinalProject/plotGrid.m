function plotGrid(x,y,dx,dy)

% Creating mesh grid
[X,Y]=meshgrid(x,y);

figure()
hold on
plot(X,Y,'k-',"LineWidth",1)
plot(Y,X,'k-',"LineWidth",1)
hold off
set(gca,'FontSize',12,"FontName","Times")
xlabel("L_x")
ylabel("L_Y")
title('Grid Configuration')

end