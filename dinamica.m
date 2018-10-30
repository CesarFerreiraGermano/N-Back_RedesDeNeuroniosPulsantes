l=load ('vandu.txt');
d=load('file_taref.txt');
#l=load ('vandu2.txt');
#d=load('file_taref2 .txt');
figure;
#lin=6;
#col=1;

escolhe = d(:,1);
v = l(:,14);
u = l(:,15);
i = l(:,16);
i0 = l(:,17);
i1 = l(:,18);
i2 = l(:,19);
i3 = l(:,20);
 
#eixoX = 1:1:50;
#plot(eixoX,i0,'go',eixoX,i1,'bo',eixoX,i2,'yo',eixoX,i3,'ro');
#set(gca,'YTick',-20:2.5:5);
#set(gca,'XTick',0:2:50);
#xlabel('Janelas');
#ylabel('I dos neuronios de entrada');
#title('I dos neuronios de entrada x Janelas');
#grid on;

value = find(escolhe == 1);
vFinal = v(value);
uFinal = u(value);
iFinal = i(value);
i0Final = i0(value);
i1Final = i1(value);
i2Final = i2(value);
i3Final = i3(value);

notValue = find(escolhe == 0);
notvFinal = v(notValue);
notuFinal = u(notValue);
notiFinal = i(notValue);
noti0Final = i0(notValue);
noti1Final = i1(notValue);
noti2Final = i2(notValue);
noti3Final = i3(notValue);

#plot3(vFinal,uFinal,iFinal,'g.',notvFinal,notuFinal,notiFinal,'r.')
#title('V x U x I');

#plot(vFinal,uFinal,'g.',notvFinal,notuFinal,'r.');
#title('V x U');

#subplot(lin,col,1)
plot(value,vFinal,'g.',notValue,notvFinal,'r.');
title('Tempo x V');
set(gca,'YTick',-100:130:30);
set(gca,'XTick',0:100:5000);
grid on;
#plot(vFinal,uFinal,'g.',notvFinal,notuFinal,'r.');
#title('V x U');

#subplot(lin,col,2)
#plot(value,uFinal,'g.',notValue,notuFinal,'r.');
#title('Tempo x U');
#set(gca,'YTick',-100:130:30);
#plot(vFinal,iFinal,'g.',notvFinal,notiFinal,'r.');
#title('V x I');

#subplot(lin,col,2)
#plot(value,iFinal,'g.',notValue,notiFinal,'r.');
#title('Tempo x I do neuronio de saida');
#set(gca,'YTick',-100:130:30);
#plot(iFinal,uFinal,'g.',notiFinal,notuFinal,'r.');
#title('I x U');

#subplot(lin,col,3)
#plot(value,i0Final,'g.',notValue,noti0Final,'r.');
#title('Tempo x I0');

#subplot(lin,col,4)
#plot(value,i1Final,'g.',notValue,noti1Final,'r.');
#title('Tempo x I1');

#subplot(lin,col,5)
#plot(value,i2Final,'g.',notValue,noti2Final,'r.');
#title('Tempo x I2');

#subplot(lin,col,6)
#plot(value,i3Final,'g.',notValue,noti3Final,'r.');
#title('Tempo x I3');


#graph = horzcat(d(:,1),l(:,10),l(:,11))