clear all
close all
clc

% ODE => { f '= g ; g = h ; -0.5*f*h }  , here η is independent variable
% initial condition f(0) = 0 , g(0) = 0 , h(0) = ? such that g(∞) = 1 ; 
% we find h(0) by obtaining improved values of h(0) that minimises the
% error g(∞)-1 to 0 
% η is of the order y/δ(x) so η_max = ∞ (10)
%% solve ODE-IVP  
tic;
eta_0 = 0;
eta_max = 10;
f0 = 0;
g0 = 0;
h0 = [0.1 1];
d_eta_Euler = 0.0001; % #0.2 not working for a good accuracy with Euler's Method, so i have choosen a low step value 
N = (eta_max - eta_0)/ d_eta_Euler;
err= 1;
%% Initializing solution
eta = eta_0 : d_eta_Euler : eta_max;
while err >10^-6
for j = 1:2      % f = F(N+1,1) ; g = F(N+1,2) ; h = F(N+1,3) ;
F(1,:) = [f0 g0 h0(j)];
%% Euler's Method
for i = 1:N
    F(i+1,:) = [  F(i,1)+F(i,2)*d_eta_Euler   F(i,2)+F(i,3)*d_eta_Euler    F(i,3)-F(i,1)*F(i,3)*d_eta_Euler*0.5 ];
end
g_inf(j) = F(end,2);
end
[err,index] = max(abs(1- g_inf));
h0_new= h0(2)+(diff(h0)/diff(g_inf))*(1-g_inf(2)); %interpolated value of h0
h0(index) = h0_new;
end
%% plotting
f1= figure; 
 plot(eta',F,'LineWidth',1);
 toc;