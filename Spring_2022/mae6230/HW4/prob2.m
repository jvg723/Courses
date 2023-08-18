clear all
close all
clc

gamma = [0.01,0.05,0.1,0.5,1,2];

alpha_dx = linspace(0,pi);

for j = 1:length(gamma)
    g = (2*gamma(j)*cos(alpha_dx)+sqrt(1-4*gamma(j)^2*sin(alpha_dx).^2))/(1+2*gamma(j));
    hold on
    plot(alpha_dx,real(g) ,'LineWidth',2)
end

ylabel('Amplification Factor - g')
xlabel('\alpha\Deltax')
legend('\gamma = 0.01','\gamma = 0.05','\gamma = 0.1','\gamma = 0.5','\gamma = 1','\gamma = 2')
