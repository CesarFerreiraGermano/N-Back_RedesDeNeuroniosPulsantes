/* ######################### MATRIZ DE CONFUSÃO ########################## *
 * ACERTOS:                                                                *
 *   Verdadeiro Positivo ou True Positive (TP): Prediz (N = N-2) e acerta  *
 *   Verdadeiro Negativo ou True Negative (TN): Prediz (N != N-2) e acerta *
 *                                                                         *
 * ERROS:                                                                  *
 *   Falso Positivo ou False Positive (FP): Prediz (N = N-2) e erra        *
 *   Falso Negativo ou False Negative (FN): Prediz (N != N-2) e erra       *
 * ####################### DINÂMICA DOS NEURÔNIOS ######################## *
 * A matriz é composta de dois vetores de tamanho [16], sendo que um pos-  *
 * sui a contabilização de acertos entre determinados neurônios de entrada *
 * nos instantes N e N-2, e o outro possui a contabilização de erros.      *
 * Significado dos índices dos vetores:                                    *
 * ____|___N-2:__|______1______|______2______|______3______|______4______| *
 *  N: |                                                                 | *
 * ____|_________________________________________________________________| *
 *  1  |                0             1             2             3      | *
 * ____|_________________________________________________________________| *
 *  2  |                4             5             6             7      | *
 * ____|_________________________________________________________________| *
 *  3  |                8             9            10            11      | *
 * ____|_________________________________________________________________| *
 *  4  |               12            13            14            15      | *
 * ____|_________________________________________________________________| *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#define JANELAS 100 // Quantidade de janelas (nº de vezes em que inicia-se um novo estímulo)

/* Função que avalia o fitness de um determinado indivíduo da população
*
* @param n int - Índivíduo da população que será testado
* @return float - Média da soma dos fitness em cada trial */
float evaluate (int n){

	FILE *file_firings, *file_dynamic, *dados, *file_tarefa, *file_quantTarefas,*poten, *file_vandu, *file_taref, *task, *file_pesos, *file_cond, *file_timedin, *file_timedin2, *taskmap,*tasksinal, *quant_din, *out_dinamica,*quant_din_w;
	int quant_dinamica;
    if(logDynamic){ // Abertura de arquivos para registro somente no último teste, com o melhor indivíduo
        file_firings  = fopen("firings.txt","w");
        file_dynamic  = fopen("file_dynamic.txt","w");
        task = fopen("task.txt","w");
        dados  = fopen("dados.txt","w");
        poten = fopen("potencial.txt","w");
        file_vandu = fopen("vandu.txt","w");
        file_taref = fopen("file_taref.txt","w");
        file_pesos = fopen("pesos.txt","w");
        file_cond = fopen("cond.txt","w");
        file_timedin = fopen("din_acertos.txt","a");
        file_timedin2 = fopen("din_tipo.txt","a");
        taskmap = fopen("taskmap.txt","a");
        tasksinal = fopen("tasksinal.txt","a");
        quant_din = fopen("dinamica_quantidade.txt","r");
	    while( (fscanf(quant_din,"%d\n", &quant_dinamica))!=EOF );
	    //fclose(quant_din);
	    out_dinamica = fopen("output.csv","r");
    }

    int sinal[JANELAS+1];
    int oi1,oi2,oi3,oi4,oi5,oi6,oi7,oi8,oi9,oi10,oi11,oi12,oi13;
    int count_dinamica = 0;
    /*while( (fscanf(out_dinamica,"%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d", &sinal[0],&sinal[1],&sinal[2],&sinal[3],&sinal[4],&sinal[5],&sinal[6],&sinal[7],&sinal[8],&sinal[9],&sinal[10],&sinal[11],&sinal[12]))!=EOF ){
    	count_dinamica++;
    	if(count_dinamica == quant_dinamica+1){
    		printf("\n\n%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n\n",sinal[0],sinal[1],sinal[2],sinal[3],sinal[4],sinal[5],sinal[6],sinal[7],sinal[8],sinal[9],sinal[10],sinal[11],sinal[12]);    		
    		break;
    	}
    }
    printf("\nOI\n%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d,%d\n\n",sinal[0],sinal[1],sinal[2],sinal[3],sinal[4],sinal[5],sinal[6],sinal[7],sinal[8],sinal[9],sinal[10],sinal[11],sinal[12]);
    quant_dinamica++;
    sinal[13] = 0;

    quant_din_w = fopen("dinamica_quantidade.txt","w");
    fprintf(quant_din_w, "%d",quant_dinamica);*/
 



//	file_tarefa  = fopen("tarefa.txt","w");

	// Define a matriz de pesos a partir do cromossomo
    for(int i=0,k=0;i<(*Iz).N;i++){
		for (int j=0;j<(*Iz).N;j++){ //fill in the column number i
            if(i==j || (j==0 || j==1 || j==2 || j==3))// Para auto-conexão e conexão com os neurônios 0,1,2,3
                (*Iz).S[j][i] = 0;
            else{
                (*Iz).S[j][i] = gene[n][k]*30-15;
                k++;
            }
        }
        //Define o alpha a partir do cromossomo.
        (*Iz).alfa[i]=0.5+gene[n][k]*9.5; //[0.5,10]
        k++;
    }

    // u x v, no instante imediatamente antes da janela 4 e diferenciar por cor
    // Ir voltando e avaliar

    if(logDynamic){
    	for(int i=0,k=0;i<(*Iz).N;i++){
			for (int j=0;j<(*Iz).N;j++){
				printf("%.2f  (%.2f)\t", (*Iz).S[j][i],(*Iz).alfa[i]);
			}
			printf("\n");
		}
    }

    // Gráfico 17-04
    float potencial[64];
    int contaQtd[64];

    for(int i = 0; i < 64; i++){
    	potencial[i] = 0;
		contaQtd[i] = 0;
    }

	// Input que será aplicado à rede
	int atual, penultimo, ultimo; // Atual = N , Penúltimo = N-1 , Último = N-2
	atual = penultimo = ultimo = -1; // Valor definido como 0 em razão de os valores referentes aos neurônios de entrada iniciarem em 1

	float TP, TN, FP, FN, // Categorias da matriz de confusão
		  TPR, // True Positive Rate ou Sensibilidade: Proporção de TP em relação à soma de TP + FN
		  TNR,
		  FPR; // True Negative Rate ou Especificidade: Proporção de TN em relação à soma de TN + FP

	float alta, // Quantidade de vezes que a frequência deve ser alta (n==n-2)
		baixa;// Quantidade de vezes que a frequência deve ser baixa (n!=n-2)

	int dinamicaNeuronios[2][16][4];
	for(int i=0; i<2; i++)
			for(int j=0; j<16; j++)
				for(int k=0; k<4; k++)
					dinamicaNeuronios[i][j][k] = 0;

	int tarefa[JANELAS]; //TODO Salvar tarefa em arquivo

	float acertosTotais, errosTotais;
	acertosTotais = errosTotais = 0;

	float fitness_trial = 0.0, // Fitness obtido em cada trial
	      fitness = 0.0; // Fitness final (média da soma dos fitness em cada trial)

	float ROC[2][trials];
	//ROC[0][0] = ROC[1][0] = 0;
	//ROC[0][20] = ROC[1][20] = 1;

	float porcentagemIgual,porcentagemDiferente;
		porcentagemIgual = porcentagemDiferente = 0;

	int acertouIgual, acertouDiferente;
	int quant;


	for (int k=0;k<trials;k++){

		int acertos_janela[JANELAS] = {0};
		int tipo_janela[JANELAS] = {0};
		int task_map[JANELAS] = {0};

		alta = baixa = TP = TN = FP = FN = TNR = TPR = FPR = quant = 0;

		int pos=0;

		// Define estado inicial para a rede
	   	(*Iz).reset_network();

	   	int sinal[JANELAS+1] = {0,3,1,2,1,0,3,0,3,1,2,0,2,0,1,0,2,3,0,1,2,1,3,2,3,1,2,0,1,0,1,2,1,2,0,3,2,0,1,2,0,1,3,2,3,0,2,1,0,3,1,3,0,1,0,1,3,1,3,0,3,1,0,1,0,3,2,0,3,0,1,3,1,0,3,2,0,1,2,0,1,2,3,0,3,2,0,2,3,2,0,1,0,2,1,2,1,3,0,2,3};
	   	//{3,2,3,1,2,0,1,0,1,3,2,0,2,0,3,0,2,1,0,3,2,3,1,2,1,3,2,0,3,0,3,2,3,2,0,1,2,0,3,2,0,3,1,2,1,0,2,3,0,1,3,1,0,3,0,3,1,3,1,0,1,3,0,3,0,1,2,0,1,0,3,1,3,0,1,2,0,3,2,0,3,2,1,0,1,2,0,2,1,2,0,3,0,2,3,2,3,1,0,2,1};
	   	int i = -1;

		for (int iterations=0; iterations<=(JANELAS*100); iterations++){

			acertouIgual = acertouDiferente = 0;

            if(iterations%100==0){ // Início de nova janela
                i++;
            	acertouIgual = 2;

            	if(iterations==100 || iterations==200){
            		pos++;
            	}

        		if(iterations>=300){ // Se já passaram as duas primeiras janelas e há, portanto, input N e input N-2
					if(atual == penultimo)
                        alta++;    
                    else
                        baixa++;

					if((((*Iz).disparos[entradas] >= limiar_pulsos)&&(atual == penultimo))){ // True Positive
						TP++;
						acertouIgual = 1;
						acertos_janela[pos] = 1;
						tipo_janela[pos] = 1;
						task_map[i] += 2;
					}

					if((((*Iz).disparos[entradas] < limiar_pulsos)&&(atual != penultimo))){ // True Negative
						TN++;
						acertouIgual = 1;
						acertos_janela[pos] = 1;
						tipo_janela[pos] = 2;
						task_map[i] += 3;
					}

					if((((*Iz).disparos[entradas] >= limiar_pulsos)&&(atual != penultimo))){ // False Positive
						FP++;
						acertouIgual = 0;
						acertos_janela[pos] = 2;
						tipo_janela[pos] = 2;
						task_map[i] += 4;
					}

					if(((*Iz).disparos[entradas] < limiar_pulsos)&&(atual == penultimo)){ // False Negative
						FN++;
						acertouIgual = 0;
						acertos_janela[pos] = 2;
						tipo_janela[pos] = 1;
						task_map[i] += 5;
					}

					pos++;

					registrarDinamica(atual,ultimo,penultimo,dinamicaNeuronios,potencial,contaQtd);
				}

				if(iterations > 0 && logDynamic && k==trials-1){
					for(int i=0;i<100;i++){
						fprintf(file_taref,"%d\n",acertouIgual);
					}
				}



				//if(saveTask){
				//	fprintf(file_tarefa,"%d ", atual);
				//}
				(*Iz).I[atual]=0; // Input do antigo atual torna-se 0
				penultimo = ultimo; // N-2 recebe antigo N-1
				ultimo = atual; // N-1 recebe antigo N
				do{
					atual = sinal[i];
					if(i==JANELAS){
						if(ultimo == 0)
							atual = 1;
						else
							atual = 0;
					}
				}while(atual == ultimo); // Novo N é calculado aleatoriamente | [0,3] atual = sinal[i]; | atual = rand()%4;
				printf("%d\n",atual);
				tarefa[quant] = atual;
				if(logDynamic && k==trials-1){
					fprintf(task, "%d\n",tarefa[quant]);
					if(i<(JANELAS-2)){
				    	fprintf(tasksinal,"%d,",sinal[i]);
				    	fprintf(taskmap,"%d,",task_map[i]);
				    }
				    else if(i==JANELAS-1){
				    	fprintf(tasksinal,"%d\n",sinal[i]);
				    	fprintf(taskmap,"%d\n",task_map[i]);
				    }
				}
				//printf("\n\nFALAAAAAAAAAAA\n\n");
				quant++;
				if(iterations>=100) // Esperar rede estabilizar
					(*Iz).I[atual]=15; // Input do atual torna-se 100
				(*Iz).disparos[entradas] = 0; // Zera disparos na janela
			}

		   	(*Iz).Update(); // TODO Comentar

			// TODO Registrar todos os resultados, e não somente o último
			if(logDynamic && k==trials-1){ // No último trial do teste com o melhor indivíduo
				fprintf(file_dynamic,"%lld",(*Iz).time);
				fprintf(file_vandu,"%lld",(*Iz).time);
			   	for (int i=0;i<(*Iz).N;i++) {// Para cada neuronio, gravar...
					fprintf(file_dynamic," %.2f %.2f %.2f %.2f %d", (*Iz).n[i].v,(*Iz).G[i],(*Iz).delta_fire[i], (*Iz).I[i], atual);
					fprintf(file_vandu," %.2f %.2f %.2f", (*Iz).n[i].v,(*Iz).n[i].u, (*Iz).I[i]);
				}
				fprintf(file_vandu," %.2f %.2f %.2f %.2f", (*Iz).Iout[0],(*Iz).Iout[1],(*Iz).Iout[2],(*Iz).Iout[3]);
				fprintf(file_pesos,"%.2f %.2f %.2f %.2f", (*Iz).sn[0],(*Iz).sn[1],(*Iz).sn[2],(*Iz).sn[3]);
				fprintf(file_cond,"%.2f %.2f %.2f %.2f", (*Iz).gn[0],(*Iz).gn[1],(*Iz).gn[2],(*Iz).gn[3]);
				fprintf(file_dynamic,"%d\n",k);
				fprintf(file_vandu,"\n");
				fprintf(file_cond,"\n");
				fprintf(file_pesos,"\n");
				
				if(iterations == (JANELAS*100)){
					for(int i=0;i<JANELAS;i++){
						fprintf(file_timedin,"%d ",acertos_janela[i]);
						fprintf(file_timedin2,"%d ",tipo_janela[i]);
					}
					fprintf(file_timedin,"\n");
					fprintf(file_timedin2,"\n");
				}


				if(iterations == (JANELAS*100)){
				   	for(int j=0; j<16 ; j++){
				   		for(int k=0; k<4; k++){
							fprintf(dados,"%d %d //N-1=%d\n",dinamicaNeuronios[0][j][k],dinamicaNeuronios[1][j][k],k);
						}
				   	}
		   	   	}
			}
		}// END for interations

		// Cálculo de TNR e TPR, evitando divisão por zero
		if((TN+FP)!=0)
            TNR=TN/(TN+FP);
		if((TP+FN)!=0)
            TPR=TP/(TP+FN);
		FPR = 1 - TNR;

        fitness_trial = 2*(TNR*TPR)/(TNR+TPR); // Cálculo de fitness semelhante ao F1 Score

		// TODO Ver se é necessário
		if(logDynamic){
			ROC[0][k] = FPR;
			ROC[1][k] = TPR;
		}

		porcentagemIgual += (TP*100)/alta;
		porcentagemDiferente += (TN*100)/baixa;

		// TODO Analisar se é realmente necessário
        if(fitness_trial<=0.01 && !logDynamic) //Termina se um dos trials já está péssimo
            return 0;

		fitness += fitness_trial;

		acertosTotais += TP + TN;
		errosTotais += FP + FN;

		

		// TODO Analisar funcionamento de logDynamic
		if(logDynamic){ // Grava apenas um trial
	            printf("\nTNR: %.3f TPR: %.3f Fitness do trial: %.3f Soma dos fitness %.4f \n(n=n-2)->%.0f   acertos:%.0f (%.1f%)\n(n!=n-2)->%.0f    acertos:%.0f (%.1f%)\n",TNR, TPR, fitness_trial,fitness,alta,TP,(TP*100)/alta,baixa,TN,(TN * 100)/baixa);
        }

	} // END for trials

	/*if(saveTask){
		fprintf(file_tarefa,"\n");
		countTask++;
		file_quantTarefas  = fopen("quantidadeTarefas.txt","w");
		fprintf(file_quantTarefas,"%d",countTask);
		fclose(file_quantTarefas);
	}*/

	porcentagemIgual /= 20;
	porcentagemDiferente /= 20;

	if(logDynamic){ // Somente depois do último trial
	            printf("TOTAL DE ACERTOS: %.0f TOTAL DE ERROS: %.0f\n",acertosTotais,errosTotais);
				float aux,aux2;
				for(int i = 1; i<trials-1;i++){
					for(int j=0; j< trials - i;j++){
						if(ROC[0][j] > ROC[0][j+1]){
							aux = ROC[0][j];
							aux2 = ROC[1][j];

							ROC[0][j] = ROC[0][j+1];
							ROC[1][j] = ROC[1][j+1];

							ROC[0][j+1] = aux;
							ROC[1][j+1] = aux2;
						}
						else if(ROC[0][j] == ROC[0][j+1]){ // Se há repetição, ordenar por TPR
							int k = j;
							while(ROC[0][k] == ROC[0][k+1]){
								if(ROC[1][k] > ROC[1][k+1]){
									aux = ROC[0][k];
									aux2 = ROC[1][k];

									ROC[0][k] = ROC[0][k+1];
									ROC[1][k] = ROC[1][k+1];

									ROC[0][k+1] = aux;
									ROC[1][k+1] = aux2;
								}
								k++;
							}
						}
					}
				}
				float y1,y2,x1,x2,coefA,coefB,valorY,area = 0;
				int indice = 0;
				y1 = x1 = area = 0;
				x2 = ROC[0][indice];
				y2 = ROC[1][indice];
				area += (y1 + y2) * (x2 - x1)/2;
				indice++;
				while(indice<20){
					x1 = x2;
					y1 = y2;
					x2 = ROC[0][indice];
					y2 = ROC[1][indice];
					area += (y1 + y2) * (x2 - x1)/2;
					indice++;
				}
				fprintf(file_firings,"0.000000 0.000000\n");
				printf("\nAREA : %.2f\n\n",area);
				printf("% N=N-2 => %.2f\n% N!=N-2 => %.2f\n",porcentagemIgual,porcentagemDiferente);
				for(int i = 0; i<trials;i++){
					if(ROC[0][i] == ROC[0][i + 1])
						;
					else{
						fprintf(file_firings,"%f %f\n",ROC[0][i],ROC[1][i]);
					}
					//printf("%f %f\n",ROC[0][i],ROC[1][i]);
				}
				fprintf(file_firings,"1.000000 1.000000\n");   	}
				if(logDynamic){
					fprintf(poten,"[");
					for(int i = 0; i< 64; i++){
						fprintf(poten,"%.2f,",potencial[i]/contaQtd[i]);
					}
					fprintf(poten,"];");
				}


	return (fitness/trials); // Média dos fitness
}
