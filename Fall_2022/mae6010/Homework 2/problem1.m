clear all
close all
clc

% stream line

y=2:0.01:20;

xstl=y+log(y-2)+1;
%xstr=log(y-2).*(y-1)+4;

t=0:0.01:20
ystr=exp(t)+2
xstr=ystr+t+1;

plot(xstl,y,'-r','linewidth',2)
hold on
plot(xstr,ystr,'-b','linewidth',2)
xlim([0 20])
ylim([0 20])
legend('streamline','streakline', 'FontSize', 20)
xlabel('y', 'FontSize', 12)
ylabel('x', 'FontSize', 12)
set(gca,'FontSize',20)