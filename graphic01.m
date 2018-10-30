l=load ('firings.txt');
figure;
lin=1;
col=1;

subplot(lin,col,1);
plot((l(:,1)),(l(:,2)),'o-');
area = trapz((l(:,1)),(l(:,2)))



