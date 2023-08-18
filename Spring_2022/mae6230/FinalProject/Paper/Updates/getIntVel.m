function [us,vs] = getIntVel(n,u,v,dt,Hx,Hy,iter)

if iter.o == 1
    us(2:n-1,1:n-1) = u(2:n-1,1:n-1) + dt*Hx(2:n-1,1:n-1);
    vs(1:n-1,2:n-1) = v(1:n-1,2:n-1) + dt*Hy(1:n-1,2:n-1);
else
    [Hx_old,Hy_old] = HHP(u_old,v_old,dxu,dxs,dyv,dys,Re);
    us(2:n-1,1:n-1) = u(2:n-1,1:n-1) + dt/2*(3*Hx(2:n-1,1:n-1) - Hx_old(2:n-1,1:n-1));
    vs(1:n-1,2:n-1) = v(1:n-1,2:n-1) + dt/2*(3*Hy(1:n-1,2:n-1) - Hy_old(1:n-1,2:n-1));
end

end