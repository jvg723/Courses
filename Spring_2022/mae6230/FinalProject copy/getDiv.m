function [div]=getDiv(imin,imax,jmin,jmax,dxi,dyi,u,v)

div=zeros(imax,jmax);

for i=imin:imax
    for j=jmin:jmax
        div(i,j) = dxi*(u(i,j)-u(i+1,j)) + dyi*(v(i,j)-v(i,j+1)); 
    end
end

return
end