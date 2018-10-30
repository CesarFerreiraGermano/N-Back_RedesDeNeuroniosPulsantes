library("gridExtra");
library(ggpubr);
library(ggplot2);

dados <- read.table("./dados.txt");

eixoX <- c(1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4);
eixoY <- c(1,2,3,4,1,2,3,4,1,2,3,4,1,2,3,4);

dados <- cbind(dados, eixoX);
dados <- cbind(dados, eixoY);

colnames(dados) <- c('acertos','erros','eixoX','eixoY');

p1 <- ggplot(data = dados, mapping = aes(eixoX,eixoY, size = acertos)) + geom_point(color='green') + xlab('Input no instante N') + ylab('Input no instante N-2') + theme(axis.text = element_text(size = 15, angle = 5)) + theme(axis.title = element_text(size = 15, angle = 0)) + scale_x_continuous(breaks = seq(0, 4, by = 1)) + scale_y_continuous(breaks = seq(0, 4, by = 1));
p2 <- ggplot(data = dados, mapping = aes(eixoX,eixoY, size = erros)) + geom_point(color='red') + xlab('Input no instante N') + ylab('Input no instante N-2') + theme(axis.text = element_text(size = 15, angle = 5)) + theme(axis.title = element_text(size = 15, angle = 0)) + scale_x_continuous(breaks = seq(0, 4, by = 1)) + scale_y_continuous(breaks = seq(0, 4, by = 1));

grid.arrange(p1,p2,labels = c('Acertos','Erros'),ncol=1,nrow=2)