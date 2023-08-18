function [pressure,pprime] = corrPres(imin,imax,jmin,jmax,x,p,alpha)

%Reallocate matricies
pprime = zeros(imax,jmax);     

%Assign pressure values
pressure = p;                                                                                                               

%Assign solution of iterative solver
pprime_interior = x;

%convert pressure correction in to a matrix
%update preesure values
z=1; 
for j=jmin:jmax
    for i=imin:imax
        pprime(i,j)=pprime_interior(z); 
        z=z+1;
        pressure(i,j) = p(i,j) + alpha*pprime(i,j);
    end
end

pressure(1,1) = 0;

return
end


