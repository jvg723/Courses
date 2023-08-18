clear all
close all
clc

utheta_max=120;                    %(mph)  circulation strength
utheta_max=utheta_max/2.237; %m/s  circulation strength

%Pressure
Pmin=944;     %(mb) minimum central pressure
Pmin=Pmin*100;   %(Pa)
Patm=1013.25; %(mb) atmopheric pressure
Patm=Patm*100;   %(Pa)

%density
rho_air=1.225; %(kg/m^3)


%Initial hurricane center location
phi_0   =28.9; %(deg) latitude
lambda_0=80.3; %(deg) longitude   

%Angle for N-NW
theta_nnw=45+(45/2); %(deg) 

%Vortex velocity
utheta_max=120;                    %(mph)  circulation strength
Vmag=13;                           %(mph)  Hurricane velocity movement magntiude
V=Vmag*[cosd(theta_nnw),sind(theta_nnw)]; %(mph) components of hurricane velocity

%Arrays for vortrex circulation velocities and position
r=1;             %Current radial position
dr=1;          %Radial increment 
rmax=100;        %Max radius to calculate velocities over
utheta=zeros(rmax,1); %rotational vortex velocities 

%Pressure
Pmin=944;     %(mb) minimum central pressure
Pmin=P*100;   %(Pa)
Patm=1013.25; %(mb) atmopheric pressure
Patm=P*100;   %(Pa)

P_R=Patm-(rho_air/2)*Utheta_max^2;

%density
rho_air=1.225; %(kg/m^3)


%Time integration parameters
t   =0;
dt  =1e-1;
tmax=1.0;

%Set initial current location for hurrican center
phi_c   =phi_0;
lambda_c=lambda_0;

%Time integrate until tmax is reached
while t<=tmax
    utheta=zeroes(rmax,1);
    r=0;
    while (utheta<utheta_max)

        if P<P_R
            utheta(r)=Omega*r;
            r=r+dr;
        elseif P>=P_R
            R=r;
            utheta(r)=(Omega*Rm^2)/r;
            r=r+dr;
        end

    end

    %Plot current hurricane position and velocity field
    figure(1)
    circle(lambda_c,phi_c,2);
    xlim([0 100]);
    ylim([0 50]);
    set(gca,'xdir','reverse','YAxisLocation','right');
    set(gca,'FontSize',24,"FontName","Times");
    title ('Rankine Model of Hurricane Matthew');
    x0=10;
    y0=10;
    width=1100;
    height=800;
    set(gcf,'position',[x0,y0,width,height]);
    %Advance huricane
    lambda_c=lambda_c+V(1)*dt;
    phi_c=phi_c+V(2)*dt;
    %Increment time
    t=t+dt;
end




