clear all
close all
clc

%Time step vector
dt_vec = 0.01:0.001:0.1;

err = zeros(length(dt_vec),1);

%Parameters
alpha1 = 0.5;
alpha2 = 1;
beta1 = 1;
beta2 = 0.75;
chi11 = 0;
chi21 = 0.1;
chi22 = 0.1;

%Funciton to evaluate for k
f = @(r) 1 - r; 

for j = 1:length(dt_vec)

    %Assigning time step
    dt = dt_vec(j);
    %Initalize time and funciton vectors
    t = 0:dt:pi;
    x = zeros(length(t),1);
    v = zeros(length(t),1);
    xt = zeros(length(t),1);
    %Inital conditions
    x(1) = 0;
    v(1) = 0;
    xt(1) = 0;

    for i = 1:(length(x))

        %RK estimation
        k1 = f(x(i)+chi11*v(i)*dt);
        k2 = f(x(i)+chi21*v(i)*dt+chi22*k1*dt^2);
        v(i+1) = v(i)+(beta1*k1+beta2*k2)*dt;
        x(i+1) = x(i)+v(i)*dt+(alpha1*k1+alpha2*k2)*dt^2;

        %Exact Solution
        xt(i+1) = 1-cos(t(i));

        clear k1 k2

    end

    %Compute and store erro at given time step
    err(j) = abs(x(end)-xt(end));

end

figure()
plot(dt_vec,err,'-o','LineWidth',2);
xlabel('\Deltat')
ylabel('Error')




