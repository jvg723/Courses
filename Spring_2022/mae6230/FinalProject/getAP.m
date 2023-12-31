function [Ap] = getAP(imin,imax,jmin,jmax,dx,dy,rho,du,dv)

%Allocate array for Ap
N = imax*jmax;
stride = jmax;
Ap = zeros(N,N);

%P-prime for the boundary nodes is set to zero
%the interior nodes imax-2*jmax-2 solved implicitly for P-prime

for j=jmin:jmax
    for i=imin:imax
        position = i + (j-1)*stride; 
        aE = 0;
        aW = 0;
        aN = 0;
        aS = 0;
        
        %set BSc for four corners
        if(i == 1 && j == 1)
            Ap(position,position) = 1;                  %pressure correction at the first node is zero
            continue;
        end
        if (i == imax && j == 1)
            Ap(position,position-1) = -rho*du(i,j)*dy;                    
            aW = -Ap(position,position-1);
            Ap(position,position+stride) = -rho*dv(i,j+1)*dx;       
            aN = -Ap(position,position+stride);
            aP = aE + aN + aW + aS;
            Ap(position,position) = aP; 
            continue;
        end
        if (i == 1 && j == jmax)
            Ap(position,position+1) = -rho*du(i+1,j)*dy;                    
            aE = -Ap(position,position+1);
            Ap(position,position-stride) = -rho*dv(i,j)*dx;  
            aS = -Ap(position,position-stride);
            aP = aE + aN + aW + aS;
            Ap(position,position) = aP;                   
            continue;
        end
        if (i == imax && j == jmax)
            Ap(position,position-1) = -rho*du(i,j)*dy;                    
            aW = -Ap(position,position-1);
            Ap(position,position-stride) = -rho*dv(i,j)*dx;       
            aS = -Ap(position,position-stride);
            aP = aE + aN + aW + aS;
            Ap(position,position) = aP;
            continue;
        end
        %set four boundaries
        if (i == 1)
            Ap(position,position+1) = -rho*du(i+1,j)*dy;                    
            aE = -Ap(position,position+1);
            Ap(position,position+stride) = -rho*dv(i,j+1)*dx;       
            aN = -Ap(position,position+stride);
            Ap(position,position-stride) = -rho*dv(i,j)*dx;       
            aS = -Ap(position,position-stride);
            aP = aE + aN + aW + aS;
            Ap(position,position) = aP;
            continue;
        end
        if (j == 1)
            Ap(position,position+1) = -rho*du(i+1,j)*dy;                    
            aE = -Ap(position,position+1);
            Ap(position,position+stride) = -rho*dv(i,j+1)*dx;       
            aN = -Ap(position,position+stride);
            Ap(position,position-1) = -rho*du(i,j)*dy;                    
            aW = -Ap(position,position-1);
            aP = aE + aN + aW + aS;
            Ap(position,position) = aP;
            continue;
        end
        if (i == imax)
            Ap(position,position+stride) = -rho*dv(i,j+1)*dx;       
            aN = -Ap(position,position+stride);
            Ap(position,position-stride) = -rho*dv(i,j)*dx;       
            aS = -Ap(position,position-stride);
            Ap(position,position-1) = -rho*du(i,j)*dy;                    
            aW = -Ap(position,position-1);
            aP = aE + aN + aW + aS;
            Ap(position,position) = aP;
            continue;
        end
        if (j == jmax)
            Ap(position,position+1) = -rho*du(i+1,j)*dy;                    
            aE = -Ap(position,position+1);
            Ap(position,position-stride) = -rho*dv(i,j)*dx;       
            aS = -Ap(position,position-stride);
            Ap(position,position-1) = -rho*du(i,j)*dy;                    
            aW = -Ap(position,position-1);
            aP = aE + aN + aW + aS;
            Ap(position,position) = aP;
            continue;
        end
        
        % interior cells
        Ap(position,position-1) = -rho*du(i,j)*dy;                          %sub diagonal
        aW = -Ap(position,position-1);

        Ap(position,position+1) = -rho*du(i+1,j)*dy;                        %%upper diagonal
        aE = -Ap(position,position+1);

        Ap(position,position-stride) = -rho*dv(i,j)*dx;                     %%sub sub diagonal
        aS = -Ap(position,position-stride);

        Ap(position,position+stride) = -rho*dv(i,j+1)*dx;                   %%upper upper diagonal
        aN = -Ap(position,position+stride);
        
        aP = aE + aN + aW + aS;
        Ap(position,position) = aP;                                          %%main diagonal
    end
end

return
end