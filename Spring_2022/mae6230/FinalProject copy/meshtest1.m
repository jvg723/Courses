clear all; close all;

alx3 = 1.0; %LENGTH X
aly3 = 1; %LENGTH Y
nx = 50; %NODES X
ny = 50; %NODES Y
str3 = 1.2; %STRETCH


%HYPERBOLIC TANGENT-TYPE CLUSTERING

nxm=nx-1;
tstr3=tanh(str3);

xc(1)=0.0;
    for kc=2:nx;
          z2dp=(2*kc-nx-1)/(nxm);
          xc(kc)=(1+tanh(str3*z2dp)/tstr3)*0.5*alx3;
    end

    
nym=ny-1;
yc(1)=0.0;

    for kc=2:ny;
          z2dp=(2*kc-ny-1)/(nym);
          yc(kc)=(1+tanh(str3*z2dp)/tstr3)*0.5*aly3;
    end
    
    
[X,Y]=meshgrid(xc,yc);

hold on; 
plot(X,Y,'k');
plot(X.',Y.','k');

axis equal;
xlim([0.0 alx3]);
ylim([0.0 aly3]);