function [ustar,du] = uMomentum(imin,imax,jmin,jmax,dx,dy,rho,mu,u,v,p,utop,alpha)

%Re-allocate arrays
ustar=zeros(imax+1,jmax);
du=zeros(imax+1,jmax);

%convective coefficients
De  = mu*dy / dx;  
Dw  = mu*dy / dx; 
Dn  = mu*dx / dy; 
Ds  = mu*dx / dy; 

A = @(F,D)( max(0, (1-0.1 * abs(F/D))^5 ) );

%compute ustar
for i = imin+1:imax
    for j = jmin+1:jmax-1
        Fe  = 0.5*rho*dy*(u(i+1,j)+u(i,j));                                     
        Fw  = 0.5*rho*dy*(u(i-1,j)+u(i,j)); 
        Fn  = 0.5*rho*dx*(v(i,j+1)+v(i-1,j+1)); 
        Fs  = 0.5*rho*dx*(v(i,j)+v(i-1,j));
        
        aE = De * A(Fe,De) + max(-Fe,0);
        aW = Dw * A(Fw,Dw) + max(Fw,0);
        aN = Dn * A(Fn,Dn) + max(-Fn,0);
        aS = Ds * A(Fs,Ds) + max(Fs,0);
        aP = aE + aW + aN + aS + (Fe-Fw) + (Fn-Fs);
        
        pressure_term = (p(i-1,j)-p(i,j)) * dy;
        
        ustar(i,j) = alpha/aP * ( (aE*u(i+1,j)+aW*u(i-1,j)+aN*u(i,j+1)+aS*u(i,j-1)) + pressure_term ) + (1-alpha)*u(i,j);
        
        du(i,j) = alpha * dy / aP;
        
    end
end

%%set du for top and bottom BCs

%bottom of the domain
j = jmin; 
for i=imin+1:imax
    Fe  = 0.5*rho*dy*(u(i+1,j)+u(i,j));                                     
    Fw  = 0.5*rho*dy*(u(i-1,j)+u(i,j)); 
    Fn  = 0.5*rho*dx*(v(i,j+1)+v(i-1,j+1)); 
    Fs  = 0;
        
    aE = De * A(Fe,De) + max(-Fe,0);
    aW = Dw * A(Fw,Dw) + max(Fw,0);
    aN = Dn * A(Fn,Dn) + max(-Fn,0);
    aS = 0;
    aP = aE + aW + aN + aS + (Fe-Fw) + (Fn-Fs);
    du(i,j) = alpha * dy / aP;
end

%top of the domain
j = jmax; 
for i=imin+1:imax
    Fe  = 0.5*rho*dy*(u(i+1,j)+u(i,j));                                     
    Fw  = 0.5*rho*dy*(u(i-1,j)+u(i,j)); 
    Fn  = 0; 
    Fs  = 0.5*rho*dx*(v(i,j)+v(i-1,j));
        
    aE = De * A(Fe,De) + max(-Fe,0);
    aW = Dw * A(Fw,Dw) + max(Fw,0);
    aN = 0;
    aS = Ds * A(Fs,Ds) + max(Fs,0);
    aP = aE + aW + aN + aS + (Fe-Fw) + (Fn-Fs);
    du(i,j) = alpha * dy / aP;
end

%Re-apply Boundary Conditions%
ustar(1,jmin:jmax)       = -ustar(2,1:jmax);    %left wall
ustar(imax+1,jmin:jmax)  = -ustar(imax,1:jmax); %right wall
ustar(imin:imax+1,1)     = 0.0;                 %bottom wall
ustar(imin:imax+1,jmax)  = utop;                %top wall 

return 
end