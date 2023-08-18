clear all
close all
clc

kdx  = linspace(0, 2*pi, 2000);
k2dx2 = 2*(1-cos(kdx));

plot(kdx,k2dx2, 'LineWidth',2)
hold on
plot(kdx,kdx.^2, 'LineWidth',2)

xlim([0 7])
ylim([0 4.5])

xlabel('k\Deltax', 'Fontsize',16)
ylabel('k`^{2}\Deltax^{2}', 'Fontsize',16)

legend('k`^{2}\Deltax^{2}','k^{2}\Deltax^{2}', 'Fontsize',16)

