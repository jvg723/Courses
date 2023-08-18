clear all
close all
clc

%Experimental parameters
g=20000; %Hz (sampling frequency)

%Read in experimental data
exp=readmatrix('veldata.txt');

%Setup struc to hold data
data.vel    =zeros(length(exp),1);
data.vel_avg=0;
data.time   =zeros(length(exp),1);
data.xpos   =zeros(length(exp),1);

%Store velocity vector 
data.vel=exp;

%Average velocity
data.vel_avg=mean(data.vel);

%Time vector
data.time(1)=1/g; %first sampling time
for i=2:length(data.vel)
    data.time(i)=data.time(i-1)+(1/g);
end

%Posistion vector
data.xpos=data.vel_avg*data.time;

%Calculate u'
data.u_prime=sqrt(mean((data.vel-data.vel_avg).^2));

%Fluctuation vector
data.u_fluc=data.vel-data.vel_avg;

%% 2.1 Velocity signal in spatial domain

%Plotting
figure(1)
plot(data.xpos,data.vel,'-b','linewidth',5)
hold on
yline(data.vel_avg,'-r','linewidth',5)
hold on
yline(data.u_prime,'-g','linewidth',5)
xlim([0 inf])
ylim([0 20])
xlabel('$x_1$ (m)','interpreter','latex')
ylabel('Velocity','interpreter','latex')
legend('$U(x_1)$ (m/s)','$\langle \boldmath{U} \rangle$ (m/s)','$u$''','interpreter','latex')
set(gca,'FontSize',48,"FontName","Times")
x0=10;
y0=10;
width=1100;
height=800;
set(gcf,'position',[x0,y0,width,height])
% print('resize','-bestfit')
% filename='figureA.pdf'
% fname='/Users/josephgiliberto/LaTex/Courses/Spring 2023/MAE 6310/report/figures'
% saveas(gca,fullfile(fname,filename),'pdf')

%% 2.2 Correlation length

% Loop through posistion xi
r=10000;
parfor i=1:r
    uxr_dot_ux=data.u_fluc(1:length(data.vel)-r).*data.u_fluc(i:length(data.vel)-r+i-1);
    uu_bar(i)=mean(uxr_dot_ux);
end

%r vector
r_vec=(data.xpos(2)-data.xpos(1))*r;
r_vec=linspace(0,r_vec,r);

%Correlation function
f=uu_bar/(mean((data.u_fluc.^2)));

%Correlation length
L=trapz(r_vec(1:3171),f(1:3171));

%Plotting
figure(2)
plot(r_vec,f,'-b','linewidth',5)
hold on
xline(L,'--k','linewidth',5)
legend('correlation function',strcat('correlation length, L=', num2str(round(L,3))))
xlim([0 1.8])
ylim([0 1])
xlabel('$r$ (m)','interpreter','latex')
ylabel('$f$','interpreter','latex')
set(gca,'FontSize',24,"FontName","Times")
print('resize','-bestfit')
% filename='figureB.pdf'
% fname='/Users/josephgiliberto/LaTex/Courses/Spring 2023/MAE 6310/report/figures'
% saveas(gca,fullfile(fname,filename),'pdf')


%% 2.3 Energy spectrum of the flow

%Calculate energy
uhat=fft(data.u_fluc);
uhat_star=conj(uhat);
E=(1/2)*(uhat.*uhat_star);
Esmooth=smoothdata(E,"movmedian",100); %Smooth data

%Normalized wave number
k=(2*pi/20000)*data.xpos;
k=k/max(k);

%Plotting energy spectrum
loglog(k(2:end),E(2:end));
ylim([10^-10 10^15])
hold on
loglog(k(2:end),Esmooth(2:end));
hold on
xline(L/(2*pi),'--k','linewidth',2)
% 
xlim([10^-8 10^1])
ylim([10^-10 10^15])
legend('Raw Data','Filtered Data',strcat('correlation length, L=', num2str(round(L,3))))
xlabel('$||k||$','interpreter','latex')
ylabel('$E(k)$','interpreter','latex')
set(gca,'FontSize',24,"FontName","Times")
x0=10;
y0=10;
width=1100;
height=800;
set(gcf,'position',[x0,y0,width,height])

%Kinetic energy comparison
E1=trapz(k,E)/max(k);

%% 2.4 The dissipation rate and Reynolds number

%Large scale measurements
C=1;
epsilon_1=C*((mean(data.u_prime)^3)/L);

% Kolmogorov length scale
eta=((0.000001^3)/epsilon_1)^1/4;

%Reynolds number
Re=(L/eta)^(-4/5);

%% 2.5 Velocity increments

r_bar=[10,0.1,0.01,0.001]; %(m) seperation distance
r_sep=ceil(r_bar/(data.xpos(2)-data.xpos(1)));

% Calculate differences in velocity fluctuations
for n=1:length(r_sep)
    parfor i=1:length(data.xpos)-r_sep(n)
               delta_u(i)=data.u_fluc(i)-data.u_fluc(i+r_sep(n));
               x_pos(i)=data.xpos(i);
    end
    figure(5)
    hold on
    plot(x_pos,delta_u,'linewidth',5)
end

legend('r=10 m','r=0.1 m','r=0.01 m','r=0.001 m')
xlim([0 inf])
ylim([-12 12])
box on
xlabel('$x_1$ (m)','interpreter','latex')
ylabel('$\delta u_1(x_1,r)$ (m/s)','interpreter','latex')
set(gca,'FontSize',48,"FontName","Times")
x0=10;
y0=10;
width=1100;
height=800;
set(gcf,'position',[x0,y0,width,height])
% print('resize','-bestfit')
% filename='figureD.pdf'
% fname='/Users/josephgiliberto/LaTex/Courses/Spring 2023/MAE 6310/report/figures'
% saveas(gca,fullfile(fname,filename),'pdf')
% 
%% 2.6 Statistics of velocity increments

r_bar=[10,0.1,0.01,0.001]; %(m) seperation distance
r_sep=ceil(r_bar/(data.xpos(2)-data.xpos(1)));

% Calculate differences in velocity fluctuations
for n=1:length(r_sep)
    parfor i=1:length(data.xpos)-r_sep(n)
               delta_u(i)=data.u_fluc(i)-data.u_fluc(i+r_sep(n));
    end
    [y,x]=ksdensity(delta_u);
    norm_pdf=normpdf(delta_u);
    figure(6)
    hold on
    subplot(1,2,1)
    plot(x,y,'linewidth',5)
    legend('r=10 m','r=0.1 m','r=0.01 m','r=0.001 m')
    xlim([-5 5])
    ylim([0 7])
    box on
    ylabel('PDF','interpreter','latex')
    xlabel('$\delta u_1(x_1,r)$ (m/s)','interpreter','latex')
    set(gca,'FontSize',24,"FontName","Times")
    hold off
    hold on
    subplot(1,2,2)
    plot(delta_u,norm_pdf,'linewidth',5)
    legend('r=10 m','r=0.1 m','r=0.01 m','r=0.001 m')
    xlim([-5 5])
    ylim([0 0.5])
    box on
    ylabel('$||PDF||$','interpreter','latex')
    xlabel('$\delta u_1(x_1,r)$ (m/s)','interpreter','latex')
    set(gca,'FontSize',24,"FontName","Times")
    hold off
end

x0=10;
y0=10;
width=1100;
height=800;
set(gcf,'position',[x0,y0,width,height])


% print('resize','-bestfit')
% filename='figureE2.pdf'
% fname='/Users/josephgiliberto/LaTex/Courses/Spring 2023/MAE 6310/report/figures'
% saveas(gca,fullfile(fname,filename),'pdf')
% 
%% 2.7 Flatness of velocity increments

r_bar=0.1:1:10; %(m) seperation distance
r_sep=ceil(r_bar/(data.xpos(2)-data.xpos(1)));

% Calculate the flatness for each r
for n=1:length(r_sep)
    parfor i=1:length(data.xpos)-r_sep(n)
               delta_u(i)=data.u_fluc(i)-data.u_fluc(i+r_sep(n));
               x_pos(i)=data.xpos(i);
    end
    F(n)=kurtosis(delta_u);
end


figure(7)
plot(r_bar,F,'-b','linewidth',5)
ylim([10^-5 10^10])
xlim([10^0 10^3])
box on
ylabel('$F(r)$','interpreter','latex')
xlabel('$r$','interpreter','latex')
set(gca,'FontSize',24,"FontName","Times")
% print('resize','-bestfit')
% filename='figureF.pdf'
% fname='/Users/josephgiliberto/LaTex/Courses/Spring 2023/MAE 6310/report/figures'
% saveas(gca,fullfile(fname,filename),'pdf')



