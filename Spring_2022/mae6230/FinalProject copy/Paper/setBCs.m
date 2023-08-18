function [u,v] = setBCs(u,v,Ulid)
% West
v(1,:) = -v(2,:);
% u(1,:) = 0;
u(2,:) = 0;
% East
v(end,:) = -v(end-1,:);
u(end,:) = 0;
% South
u(:,1) = - u(:,2);
% v(:,1) = 0;
v(:,2) = 0;
% North
u(:,end) = (2*Ulid - u(:,end-1));
v(:,end) = 0;
end