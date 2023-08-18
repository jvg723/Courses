function [vstar,dv] = vMomentum(imin,imax,jmin,jmax,dx,dy,rho,mu,u,v,p,alpha)

%Re-allocate arrays
vstar=zeros(imax,jmax+1);
dv=zeros(imax,jmax+1);

%convective coefficients
De  = mu*dy / dx;  
Dw  = mu*dy / dx; 
Dn  = mu*dx / dy; 
Ds  = mu*dx / dy; 

A = @(F,D)( max(0, (1-0.1 * abs(F/D))^5 ) );

%Compute vstar
for i = imin+1:imax-1
    for j = jmin+1:jmax
        Fe  = 0.5*rho*dy*(u(i+1,j)+u(i+1,j-1));                                     
        Fw  = 0.5*rho*dy*(u(i,j)+u(i,j-1)); 
        Fn  = 0.5*rho*dx*(v(i,j)+v(i,j+1)); 
        Fs  = 0.5*rho*dx*(v(i,j-1)+v(i,j));
        
        aE = De * A(Fe,De) + max(-Fe,0);
        aW = Dw * A(Fw,Dw) + max(Fw,0);
        aN = Dn * A(Fn,Dn) + max(-Fn,0);
        aS = Ds * A(Fs,Ds) + max(Fs,0);
        aP = aE + aW + aN + aS + (Fe-Fw) + (Fn-Fs);
        
        pressure_term = (p(i,j-1)-p(i,j)) * dx;
        
        vstar(i,j) = alpha/aP * ( (aE*v(i+1,j)+aW*v(i-1,j)+aN*v(i,j+1)+aS*v(i,j-1)) + pressure_term ) + (1-alpha)*v(i,j);
        
        dv(i,j) = alpha * dx / aP; 
        
    end
end


%%set dv for top and bottom BCs

%left side of the domain
i = imin;  
for j=jmin+1:jmax
    Fe  = 0.5*rho*dy*(u(i+1,j)+u(i+1,j-1));                                     
    Fw  = 0; 
    Fn  = 0.5*rho*dx*(v(i,j)+v(i,j+1)); 
    Fs  = 0.5*rho*dx*(v(i,j-1)+v(i,j));                                                       
        
    aE = De * A(Fe,De) + max(-Fe,0);
    aW = 0;
    aN = Dn * A(Fn,Dn) + max(-Fn,0);
    aS = Ds * A(Fs,Ds) + max(Fs,0);
    aP = aE + aW + aN + aS + (Fe-Fw) + (Fn-Fs);
    dv(i,j) = alpha * dx / aP;
end

%right side of the domain
i = imax;  
for j=jmin+1:jmax
    Fe  = 0;                                     
    Fw  = 0.5*rho*dy*(u(i,j)+u(i,j-1)); 
    Fn  = 0.5*rho*dx*(v(i,j)+v(i,j+1)); 
    Fs  = 0.5*rho*dx*(v(i,j-1)+v(i,j));
        
    aE = 0;
    aW = Dw * A(Fw,Dw) + max(Fw,0);
    aN = Dn * A(Fn,Dn) + max(-Fn,0);
    aS = Ds * A(Fs,Ds) + max(Fs,0);
    aP = aE + aW + aN + aS + (Fe-Fw) + (Fn-Fs);
    dv(i,j) = alpha * dx / aP;
end

%Re-apply Boundary Conditions%
vstar(1,1:jmax+1)        = 0.0;                 %left wall
vstar(imax,1:jmax+1)     = 0.0;                 %right wall
vstar(1:imax,1)          = -vstar(1:imax,2);    %bottom wall
vstar(1:imax,jmax+1)     = -vstar(1:imax,jmax); %top wall 

return 
end