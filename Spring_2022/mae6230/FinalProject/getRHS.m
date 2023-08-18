function [bp] = getRHS(imin,imax,jmin,jmax,dx,dy,rho,ustar,vstar)

bp=zeros((jmax-2)*(imax-2),1);    %vector of RHS for solving pressure corrections
stride = jmax;

% RHS is the same for all nodes except the p_prime(1,1)
% because p(1,1) is set to be zero, it has no pressure correction
for j=jmin:jmax
    for i=imin:imax

        position = i + (j-1)*stride; 
        bp(position) = rho * (ustar(i,j)*dy - ustar(i+1,j)*dy + vstar(i,j)*dx - vstar(i,j+1)*dx); 
        
    end
end

% modify for pprime(1,1)
bp(1,1) = 0;

return 
end
