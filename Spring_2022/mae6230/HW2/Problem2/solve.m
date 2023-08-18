clear all
close all 
clc

syms c1 c2 pi

eqn1 = (pi^4/3)+(pi^3)*c2 == c1
eqn2 = (pi^5/4)+(pi/2)*c1+(3*pi^2/4)*c2 == c1

sol = solve([eqn1,eqn2],[c1,c2])