%%%solve 2D Burgers Equation%%%
clc
clear all
close all

%Parameters
nu = 0.015;

%Computational Domain
Lx = 1;     %Length in x
Ly = 1;     %Length in y
nx = 40;    %Number of cells in x direction
ny = 40;    %Number of cells in y direciton
dx = Lx/nx;     %Grid spacing in x
dy = Ly/ny;     %Grid spacing in y
x = linspace(0,Lx,nx);   %x Grid Cooridnates
y = linspace(0,Ly,ny);   %y Grid Coordinates
[X,Y] = meshgrid(x,y);

%Time Stepping
t = 10;         %Total duration of simulation
dt = 0.01;       %Time step size
nmax = t/dt;    %Max number of time steps

%Allocate Arrays for velocity with random IC
u = rand(nx,ny);
v = rand(nx,ny);

%Logical operators for initial conditions 
X0 = 1;     %x zero poisiton
Y0 = 1;     %y zero position
XL = nx;    %x final position
YL = ny;    %y final position

%%Enforce BC in initial velocity feilds%%

%u Boundary Conditions
u(:,X0) = 0;
u(:,XL) = 0;
u(Y0,:) = sind(2*pi*x);
u(YL,:) = sind(2*pi*x);

%v Boundary Conditions
v(:,Y0) = 1-y;
v(:,YL) = 1-y;
v(X0,:) = 1;
v(XL,:) = 0;

figure(1)
surf(X,Y,u)
xlabel('x')
ylabel('y')
zlabel('u')
xlim([0 1])
ylim([0 1])
zlim([0 0.15])
title("u velocity, IC")

figure(2)
surf(X,Y,v)
xlabel('x')
ylabel('y')
zlabel('v')
xlim([0 1])
ylim([0 1])
zlim([0 1.5])
title("v velocity, IC")

for n = 1:nmax

    for i = 2:(nx-1)  %Looping over x

        for j = 2:(ny-1)  %Looping over y

            %Solve u velocity
            u(i,j) = u(i,j)-u(i,j)*(dt/dx)*(u(i+1,j)-u(i-1,j))...
                -v(i,j)*(dt/dy)*(u(i,j+1)-u(i,j-1))...
                +(nu*dt/dx^2)*(u(i+1,j)-2*u(i,j)+u(i-1,j))...
                +(nu*dt/dy^2)*(u(i,j+1)-2*u(i,j)+u(i,j-1));

            %Solve v velocity
            v(i,j) = v(i,j)-u(i,j)*(dt/dx)*(v(i+1,j)-v(i-1,j))...
                -v(i,j)*(dt/dy)*(v(i,j+1)-v(i,j-1))...
                +(nu*dt/dx^2)*(v(i+1,j)-2*v(i,j)+v(i-1,j))...
                +(nu*dt/dy^2)*(v(i,j+1)-2*v(i,j)+v(i,j-1));

            %u Boundary Conditions
            u(:,X0) = 0;
            u(:,XL) = 0;
            u(Y0,:) = sind(2*pi*x);
            u(YL,:) = sind(2*pi*x);

            %v Boundary Conditions
            v(:,Y0) = 1-y;
            v(:,YL) = 1-y;
            v(X0,:) = 1;
            v(XL,:) = 0;
        end

    end

    figure(3)
    surf(X,Y,u)
    xlabel('x')
    ylabel('y')
    zlabel('u')
    xlim([0 1])
    ylim([0 1])
    zlim([0 0.15])
    title(["u velocity, n=",n])

    figure(4)
    surf(X,Y,v)
    xlabel('x')
    ylabel('y')
    zlabel('v')
    xlim([0 1])
    ylim([0 1])
    zlim([0 1.5])
    title(["v velocity, n=",n])

    pause(0.1)

end





