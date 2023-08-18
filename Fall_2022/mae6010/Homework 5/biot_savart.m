clear all
close all
clc

% Domain Parameters
N=100;
L=1;
Uinf=1;
h=0.25*L;
% h=0.1*L;
epsilon=(4*L)/N;
ez=[0 0 1];
gammaj_p=+(Uinf*L)/N;
gammaj_m=-(Uinf*L)/N;

%Time integration parameters
t=0;
dt=1e-3;
tmax=1.6;

%Initalize the vortex sheet
A=0.05*L;
lambda=L;
xvec=linspace(0,L-L/N,N);
yvec=A*sin((2*pi/lambda)*xvec);
zvec=zeros(1,N);

% Initalize time step velocity vector
uvec=zeros(1,3);

%% One vortex sheet simulation

% % Time integrate until tmax is reached
% while t<=tmax
%     % Find location where vortex leaves domain
%     xvec_plot=xvec;
%     yvec_plot=yvec;
%     index_L=find(xvec>L);
%     index_0=find(xvec<0);
%     xvec_plot(index_L)=xvec(index_L)-L;
%     xvec_plot(index_0)=xvec(index_0)+L;
%     % Plot updated vortex sheets
%     figure(1)
%     scatter(xvec_plot,yvec_plot,'b','filled')
%     xlim([0 1]);
%     ylim([-0.7 0.7]);
%     set(gca,'FontSize',24,"FontName","Times");
%     title (['time: ',sprintf('%0.3f',t)]);
%     x0=10;
%     y0=10;
%     width=1100;
%     height=800;
%     set(gcf,'position',[x0,y0,width,height]);
%     % Store old position vectors
%     xvec_old=xvec;
%     yvec_old=yvec;
%     zvec_old=zvec;
%     % Loop over all vortex locations
%     for i=1:N
%         %Curent vortex location
%         xi = [xvec_old(i) yvec_old(i) zvec_old(i)];
%         % Clear velocity vector for time step
%         uvec=zeros(1,3);
%         for j=1:N
%             if i~=j
%                 %xj location
%                 xj=[xvec_old(j),yvec_old(j),zvec_old(j)];
%                 %Seperation distance
%                 xsep=(xi(1)-xj(1))-round((xi(1)-xj(1))/L)*L; %x periodicity
%                 ysep=(xi(2)-xj(2));
%                 zsep=(xi(3)-xj(3));
%                 sep=[xsep,ysep,zsep];
%                 %Radius between vortex xi and xj
%                 r=sqrt((xsep)^2+(ysep)^2+(zsep)^2);
%                 %Smooth Gausian function
%                 f=1-exp(-(r^2)/(2*epsilon^2));
%                 %Increment velocity for current xi
%                 uvec=uvec+gammaj_m*f*(cross(ez,sep)/(r^2));
%             end
%         end
%         % Scale velocity by 1/(2pi)
%         uvec=(1/(2*pi))*uvec;
%         %Time integration
%         xvec(i)=xvec(i)+uvec(1)*dt;
%         yvec(i)=yvec(i)+uvec(2)*dt;
%         zvec(i)=zvec(i)+uvec(3)*dt;
%     end
%     %Increment time
%     t=t+dt;
% end

%% Two vortex sheet simulation

% Vectors for two vortex sheets [bottom sheet;top sheet]
xvec=[xvec,xvec];
yvec=[yvec,yvec+h];
zvec=[zvec,zvec];

%Circulation vector
gammaj_vec=ones(1,2*N);
gammaj_vec(1:N)=gammaj_vec(1:N)*gammaj_m;
gammaj_vec(N+1:2*N)=gammaj_vec(N+1:2*N)*gammaj_p;

%Time integrate until tmax is reached
while t<=tmax
    % Find location where vortex leaves domain
    xvec_plot=xvec;
    yvec_plot=yvec;
    index_L=find(xvec>L);
    index_0=find(xvec<0);
    xvec_plot(index_L)=xvec(index_L)-L;
    xvec_plot(index_0)=xvec(index_0)+L;
    % Plot updated vortex sheets
    figure(1)
    scatter(xvec_plot(1:N),yvec_plot(1:N),'b','filled')
    hold on
    scatter(xvec_plot(N+1:2*N),yvec_plot(N+1:2*N),'r','filled') 
    hold off
    xlim([-0.2 1.2]);
    ylim([-0.7 0.7]);
    set(gca,'FontSize',24,"FontName","Times");
    title ({['time: ',sprintf('%0.3f',t)],['h=',sprintf('%0.2f',h)]});
    x0=10;
    y0=10;
    width=1100;
    height=800;
    set(gcf,'position',[x0,y0,width,height]);
    % Store old position vectors
    xvec_old=xvec;
    yvec_old=yvec;
    zvec_old=zvec;
    % Loop over all vortex locations
    for i=1:2*N
        %Curent vortex location
        xi=[xvec_old(i),yvec_old(i),zvec_old(i)];
        % Clear velocity vector for time step
        uvec=zeros(1,3);
        for j=1:2*N
            if i~=j
                %xj location
                xj=[xvec_old(j),yvec_old(j),zvec_old(j)];
                %Seperation distance
                xsep=(xi(1)-xj(1))-round((xi(1)-xj(1))/L)*L; %x periodicity
                ysep=(xi(2)-xj(2));
                zsep=(xi(3)-xj(3));
                sep=[xsep,ysep,zsep];
                %Radius between vortex xi and xj
                r=sqrt((xsep)^2+(ysep)^2+(zsep)^2);
                %Smooth Gausian function
                f=1-exp(-(r^2)/(2*epsilon^2));
                %Increment velocity for current xi
                uvec=uvec+gammaj_vec(j)*f*(cross(ez,sep)/(r^2));
            end
        end
        % Scale velocity by 1/(2pi)
        uvec=(1/(2*pi))*uvec;
        %Time integration
        xvec(i)=xvec(i)+uvec(1)*dt;
        yvec(i)=yvec(i)+uvec(2)*dt;
        zvec(i)=zvec(i)+uvec(3)*dt;
    end
    %Increment time
    t=t+dt;
end
