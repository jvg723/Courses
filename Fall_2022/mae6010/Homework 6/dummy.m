load('wind','x','y','u','v')
X = x(11:22,11:22,1);
Y = y(11:22,11:22,1);
U = u(11:22,11:22,1);
V = v(11:22,11:22,1);

quiver(X,Y,U,V)
axis equal



% radius=[10 15 20 30]
% velocity=[5 2.5 15 20]
% colors=['y','m','c','r'] % This is to just make the points different colors
% p=zeros(4,1); %here we will store the handles to delete the point 
% hold on
% for i=1:4 %Loop to create multiple circles
% th=0:pi/50:2*pi;
% xunit=radius(i)*cos(th);
% yunit=radius(i)*sin(th);
% h=plot(xunit,yunit); 
% p(i)=plot(xunit(1),yunit(1),'o','MarkerFaceColor',colors(i),'Color',colors(i)); 
% %creates a point on each graph
% end
% time=[0:0.001:100]; %time vector in seconds
% for t=1:length(time)
%     for i=1:4 %Loop to create multiple circles
%         delete(p(i)); %delete the old point
%         %computes the new angle for each point as velocity*time
%         xunit=radius(i)*cos(velocity(i)*time(t)); 
%         yunit=radius(i)*sin(velocity(i)*time(t)); 
%         %creates a point on each graph
%         p(i)=plot(xunit(1),yunit(1),'o','MarkerFaceColor',colors(i),'Color',colors(i));                
%     end
%     pause(0.01); %wait 0.01 seconds so the plot is displayed
% end
% hold off