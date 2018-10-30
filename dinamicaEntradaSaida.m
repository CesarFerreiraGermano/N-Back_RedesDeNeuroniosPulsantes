l=load ('file_dynamic.txt');
figure;
lin=5;
col=1;


subplot(lin,col,1);
plot(l(:,1),l(:,2));
axis([0,5000,-100,30]);
title('Neuronios de entrada');
set(gca,'YTick',-100:130:30);

subplot(lin,col,2);
plot(l(:,1),l(:,7));
axis([0,5000,-100,30]);
set(gca,'YTick',-100:130:30);

subplot(lin,col,3);
plot(l(:,1),l(:,12));
axis([0,5000,-100,30]);
set(gca,'YTick',-100:130:30);

subplot(lin,col,4);
plot(l(:,1),l(:,17));
axis([0,5000,-100,30]);
set(gca,'YTick',-100:130:30);

subplot(lin,col,5);
plot(l(:,1),l(:,22));
axis([0,5000,-100,30]);
title('Neuronio de saida');
set(gca,'YTick',-100:130:30);
