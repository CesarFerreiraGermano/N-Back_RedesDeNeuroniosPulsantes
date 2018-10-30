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

#define JANELAS 10000 // Quantidade de janelas (nº de vezes em que inicia-se um novo estímulo)

/* Função que avalia o fitness de um determinado indivíduo da população
*
* @param n int - Índivíduo da população que será testado
* @return float - Média da soma dos fitness em cada trial */
float evaluate (int n){

	FILE *file_firings, *file_dynamic, *dados, *file_tarefa, *file_quantTarefas;
    if(logDynamic){ // Abertura de arquivos para registro somente no último teste, com o melhor indivíduo
        file_firings  = fopen("firings.txt","w");
        file_dynamic  = fopen("file_dynamic.txt","w");
        dados  = fopen("dados.txt","w");
    }

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

	// Input que será aplicado à rede
	int atual, penultimo, ultimo; // Atual = N , Penúltimo = N-1 , Último = N-2
	atual = penultimo = ultimo = 0; // Valor definido como 0 em razão de os valores referentes aos neurônios de entrada iniciarem em 1

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

	for (int k=0;k<trials;k++){



		alta = baixa = TP = TN = FP = FN = TNR = TPR = FPR = 0;

		// Define estado inicial para a rede
	   	(*Iz).reset_network();

		for (int iterations=0; iterations<=(JANELAS*100); iterations++){

            if(iterations%100==0){ // Início de nova janela

        		if(iterations>=300){ // Se já passaram as duas primeiras janelas e há, portanto, input N e input N-2
					if(atual == penultimo)
                        alta++;
                    else
                        baixa++;

					if((((*Iz).disparos[entradas] >= limiar_pulsos)&&(atual == penultimo))) // True Positive
						TP++;

					if((((*Iz).disparos[entradas] < limiar_pulsos)&&(atual != penultimo))) // True Negative
						TN++;

					if((((*Iz).disparos[entradas] >= limiar_pulsos)&&(atual != penultimo))) // False Positive
						FP++;

					if(((*Iz).disparos[entradas] < limiar_pulsos)&&(atual == penultimo)) // False Negative
						FN++;

					registrarDinamica(atual,ultimo,penultimo,dinamicaNeuronios);
				}

				//if(saveTask){
				//	fprintf(file_tarefa,"%d ", atual);
				//}
				(*Iz).I[atual]=0; // Input do antigo atual torna-se 0
				penultimo = ultimo; // N-2 recebe antigo N-1
				ultimo = atual; // N-1 recebe antigo N
				do{atual = rand()%4;}while(atual == ultimo); // Novo N é calculado aleatoriamente | [0,3]
				(*Iz).I[atual]=15; // Input do atual torna-se 100
				(*Iz).disparos[entradas] = 0; // Zera disparos na janela
			}

		   	(*Iz).Update(); // TODO Comentar

			// TODO Registrar todos os resultados, e não somente o último
			if(logDynamic && k==trials-1){ // No último trial do teste com o melhor indivíduo
				fprintf(file_dynamic,"%lld",(*Iz).time);
			   	for (int i=0;i<(*Iz).N;i++) // Para cada neuronio, gravar...
					fprintf(file_dynamic," %.2f %.2f %.2f %.2f %d", (*Iz).n[i].v,(*Iz).G[i],(*Iz).delta_fire[i], (*Iz).I[i], atual);
				fprintf(file_dynamic,"%d\n",k);

				if(iterations == 5000){
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


	return (fitness/trials); // Média dos fitness
}
