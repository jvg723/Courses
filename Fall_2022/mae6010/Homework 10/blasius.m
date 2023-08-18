clear all
close all
clc

%Range of eta values
etaspan = [0 5];

%Initial Conditions
F0=0;           %F(0)
Fp0=0;          %F'(0)
Fpp0=[0.1 1];   %F''(0) Initial gueses

%Error
err=1;
tol=10^-6;

while err>tol
    %Loop over initial conditions
    for i=1:length(Fpp0)
        %Solve system using ODE45
        IC=[F0;Fp0;Fpp0(i)];
        [eta,F]=ode45(@odefun, etaspan, IC);
        %Store F'(inf) value for current guess
        Fp_inf(i) = F(end,2);
    end
    %Update guess
    [err,index] = max(abs(1- Fp_inf));
    Fpp0_new= Fpp0(2)+(diff(Fpp0)/diff(Fp_inf))*(1-Fp_inf(2)); 
    Fpp0(index) = Fpp0_new;
end

%Plot F,F',F'' vs eta
figure(1)
plot(eta,F,'linewidth',10)
xlim([0 400])
ylim([0 3])
set(gca,'FontSize',56,"FontName","Times");
xlim([0 5]);
x0=10;
y0=10;
width=1100;
height=800;
set(gcf,'position',[x0,y0,width,height]);
legend('$F$','$F''$','$F''''$','interpreter','latex')
xlabel('$\eta$','interpreter','latex')

%Plot u
U=2.4;          %m/s
mu_rho=1*10^-5; %m^2/s
x=[0.01,1,100,10000];

for k=1:length(x)
    u=U*F(:,2);
    y=eta/sqrt((U/2)*(1/x(i))*(1/mu_rho));

    figure()
%     hold on
    plot(u,y,'linewidth',10)
%     xlim([0 400])
%     ylim([0 3])
    set(gca,'FontSize',56,"FontName","Times");
    x0=10;
    y0=10;
    width=1100;
    height=800;
    set(gcf,'position',[x0,y0,width,height]);
%     legend('$x=1 cm$','$x=1 m$','$x=100 m$','$x=100,000 m$','interpreter','latex')
    ylabel('$y$','interpreter','latex')
    xlabel('$u$','interpreter','latex')
    title(['x=',sprintf('%d',x(k)),' m'])

end



%Function to hold F,F',F''
function dFdeta=odefun(eta,F)
    dFdeta=zeros(3,1);
    dFdeta(1)=F(2);
    dFdeta(2)=F(3);
    dFdeta(3)=-F(1)*F(3);
end










