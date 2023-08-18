clear all
close all
clc

global beta

%Range of eta values
etaspan = 0:0.01:5;

%Beta vector
beta_vec=[0.6,0.3,0,-0.1,-0.18,-0.198838];

%Fluid properites
mu_rho=1*10^-5; %m^2/s

%Initial Conditions
F0=0;           %F(0)
Fp0=0;          %F'(0)
Fpp0=[0.1 1];   %F''(0) Initial gueses

%Error
err=1;
tol=10^-6;

%Loop over beta values
for j=1:length(beta_vec)
    %Set current beta value
    beta=beta_vec(j);
    txt=['\beta= ',num2str(beta)];
    while err>tol
        %Loop over initial conditions
        for k=1:length(Fpp0)
            %Solve system using ODE45
            IC=[F0;Fp0;Fpp0(k)];
            [eta,F]=ode45(@odefun, etaspan,IC);
            %Store F'(inf) value for current guess
            Fp_inf(k) = F(end,2);
        end
        %Update guess
        [err,index] = max(abs(1- Fp_inf));
        Fpp0_new= Fpp0(2)+(diff(Fpp0)/diff(Fp_inf))*(1-Fp_inf(2));
        Fpp0(index) = Fpp0_new;
    end
    %Find eta_99
    [eta_pos]=find(F(:,2)<0.9901);
    eta_99=eta(eta_pos(end));

    %Plot u/U vs eta
    figure(1)
    hold on
    plot(F(:,2),eta,'linewidth',10,'DisplayName',txt)
    set(gca,'FontSize',56,"FontName","Times");
    x0=10;
    y0=10;
    width=1100;
    height=800;
    set(gcf,'position',[x0,y0,width,height]);
    xlabel('$u/U$','interpreter','latex')
    ylabel('$\eta$','interpreter','latex')
    legend show

     %Plot u/U vs y/eta_99
    figure(2)
    hold on
    plot(F(:,2),eta/eta_99,'linewidth',10,'DisplayName',txt)
    set(gca,'FontSize',56,"FontName","Times");
    x0=10;
    y0=10;
    width=1100;
    height=800;
    set(gcf,'position',[x0,y0,width,height]);
    xlabel('$u/U$','interpreter','latex')
    ylabel('$y/\delta_{99}$','interpreter','latex')
    legend show
    
    %Rest error
    err=1;
end


%Function to hold F,F',F''
function dFdeta=odefun(eta,F)
    global beta
    beta
    dFdeta=zeros(3,1);
    dFdeta(1)=F(2);
    dFdeta(2)=F(3);
    dFdeta(3)=-F(1)*F(3)-beta*(1-F(2)^2);
end










