l=load ('logGenetico.txt');
figure;
lin=1;
col=1;

eixoX = 0:1:8500;

subplot(lin,col,1);
plot((eixoX),(l(:,4)));
hold on;
plot((eixoX),(l(:,3)));
axis([0 8500 0.7 0.9]);
title('5 neurônios');




