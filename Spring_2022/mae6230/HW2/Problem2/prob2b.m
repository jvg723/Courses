clear all
close all
clc

x = linspace(0,2*pi,1000);

phi_ex = sin(3*x);

phi_app = pi*x.^2+(0.5)*1.5*sin(3*x)-3*x.^2*1;

plot(x,phi_ex, 'LineWidth',2)
hold on
plot(x,phi_app, 'LineWidth',2)

xlim([0 8])
ylim([-4 4])

xlabel('x', 'Fontsize',16)
ylabel('\phi(x)', 'Fontsize',16)

legend('\phi(x)','\phi(x)_{approx}', 'Fontsize',16)