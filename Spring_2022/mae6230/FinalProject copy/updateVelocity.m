function [u,v] = updateVelocity(imin,imax,jmin,jmax,ustar,vstar,pprime,du,dv,utop)

%Re-allocate arrays
v = zeros(imax,jmax+1);
u = zeros(imax+1,jmax);

%update interior nodes of u and v
for i=imin+1:imax
    for j=jmin+1:jmax-1
        
        u(i,j) = ustar(i,j) + du(i,j)*(pprime(i-1,j)-pprime(i,j));
        
    end
end

for i=imin+1:imax-1
    for j=jmin+1:jmax
        
        v(i,j) = vstar(i,j) + dv(i,j)*(pprime(i,j-1)-pprime(i,j));
        
    end
end

%Apply Boundary Conditions%
[u,~,v] = applyBC(imin,imax,jmin,jmax,u,ustar,utop,vstar);

return
end
