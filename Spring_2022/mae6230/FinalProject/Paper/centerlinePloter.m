close all
clc

litURe1000 = readmatrix("uVelRe1000.csv");
litURe100 = readmatrix("uVelRe100.csv");
litVRe1000 = readmatrix("vVelRe1000.csv");
litVRe100 = readmatrix("vVelRe100.csv");
simVRe1000n100 = xlsread('simData.xlsx',1);
simURe1000n100 = xlsread('simData.xlsx',2);
simVRe1000n120 = xlsread('simData.xlsx',3);
simURe1000n120 = xlsread('simData.xlsx',4);

udataLit = litURe1000;
vdataLit = litVRe1000;
udataSim100 = simURe1000n100;
vdataSim100 = simVRe1000n100;
udataSim120 = simURe1000n120;
vdataSim120 = simVRe1000n120;

h1 = figure(1);
plot(udataSim100(:,1),udataSim100(:,2),'-r','LineWidth',2)
hold on
plot(udataSim120(:,1),udataSim120(:,2),'-g','LineWidth',2)
hold on
plot(udataLit(:,1),udataLit(:,2),'bo','LineWidth',2)
hold off
axis([-0.4,0.8,0,1])
xlabel('{\it u_c}','fontsize',24,'FontName','Times')
ylabel('{\it y}','fontsize',24,'FontName','Times')
legend('{\it n_x}=100 \times {\it n_y}=100','{\it n_x}=120 \times {\it n_y}=120','Ghia et al. (1982)','Location','SouthEast')
ax = gca;
ax.FontSize = 18;
ax.FontName = 'Times';

figure(2)
plot(vdataSim100(:,1),vdataSim100(:,2),'-r','LineWidth',2)
hold on;
plot(vdataSim120(:,1),vdataSim120(:,2),'-g','LineWidth',2)
hold on;
plot(vdataLit(:,1),vdataLit(:,2),'bo','LineWidth',2)
hold off;
axis([0,1,-0.5,0.4])
xlabel('{\it x}','fontsize',24,'FontName','Times')
ylabel('{\it v_c}','fontsize',24,'FontName','Times')
legend('{\it n_x}=100 \times {\it n_y}=100','{\it n_x}=120 \times {\it n_y}=120','Ghia et al. (1982)','Location','NorthEast')
ax = gca;
ax.FontSize = 18;
ax.FontName = 'Times';
