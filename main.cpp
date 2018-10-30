#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <sys/resource.h>
#include <unistd.h>

#define NEURONS 5 // Quantidade de neurônios

#define writeBestGene 1 // Salva o melhor genótipo da simulação em um arquivo
#define writePopulation 1 // Salva a última população de uma simulação em um arquivo

// Variáveis carregadas do arquivo config.txt
bool loadPopulationFromFile; // Carrega todos os genótipos de indivíduos de um arquivo
bool logDynamic; // Salva a dinâmica de um indivíduo (geralmente o melhor)
bool loadBestGeneFromFile; // Carrega o melhor indivíduo da última simulação
bool saveTask; // Salva tarefa N-Back em arquivo
bool readTask; // Lê tarefa N-Back de arquivo
int  trials; // Número de vezes que um indivíduové testado em cada evaluate
int  end;
int  start;		// TODO COMENTAR start value  logGA (column "iteration")
int quantTask;
int countTask = 0;

int limiar_pulsos=0;
//Protótipos
float evaluate (int n );
#include "izhikevich.h" // Operações básicas da rede neural (Izhikevich Model)
#include "extras.h" // void init_pop(); void write_pop(int best); void read_conf_file();
#include "genetico.h" // Funcionamento do algoritmo genético

Izhikevich_network  *Iz; //Variavel global.
#include "estudo.h"
#include "evaluate.h" // Avalia um indivíduo da população


int main(int argc, char *argv[]){

	if(argc!=2){ // Exemplo: ./a.out 1
		printf("main <limiar de pulsos para o genetico> \n");
		return 0;
	}
	limiar_pulsos = atoi(argv[1]);

	int quantidadeGeracoes;

	FILE *arq3 = fopen("quantidadeTarefas.txt","r");
	while( (fscanf(arq3,"%d", &quantTask))==1 );
	printf("%d\n",quantTask);
	countTask = quantTask;
	fclose(arq3);

	int t;
    unsigned long semente = time(0);
	//printf("\nSemente utilizada: %ld \n",semente);
    srand48(semente); srand (semente);

	read_conf_file(); // Leitura do arquivo de configuração da simulação

	FILE * file= fopen("logGA.txt","w");//Armazena evolução do GA
	//Escolhe os dois primeiros individuos

	//Cria a rede apenas 1 vez. Dependendo do modelo, esta solucao pode nao funcionanar.
	Iz = new Izhikevich_network(NEURONS);
	Genetico * G = new Genetico();

	// LÓGICA PARA SALVAR NÚMERO DE GERAÇÕES
	FILE *arq2 = fopen("quantidadeGeracoes.txt","r");

	while( (fscanf(arq2,"%d\n", &quantidadeGeracoes))!=EOF )
		(*G).geracao = quantidadeGeracoes; // Para não reiniciar taxa de cruzamento sempre que carregar população

	fclose(arq2);
	// END

	(*G).init_pop();//inicializa a população

	for (t=0;t<end;t++){
        if((*G).produzir_nova_geracao()==1)
            break;
        (*G).write_pop(0);

        printf("%6d %2d %.5f %.5f %.15lf\n",t,(*G).best,(*G).avaliacao_best,(*G).media_populacao,(*G).porcentagem_mutacao);
        fprintf(file,"%6d %2d %.5f %.5f %.15lf\n",t,(*G).best,(*G).avaliacao_best,(*G).media_populacao,(*G).porcentagem_mutacao);
        fflush(file);

        if(t%20==0){
        	struct rusage ru;
        	getrusage(RUSAGE_SELF, &ru);
            double tempo_execucao=ru.ru_utime.tv_sec+ ru.ru_utime.tv_usec/1000000.0+
											ru.ru_stime.tv_sec+ ru.ru_stime.tv_usec/1000000.0;
            //if(tempo_execucao > (1*60*60+30*60)){//5 horas
              //  printf("\nTempo esgotado. Tempo em execucao: %lf", tempo_execucao );
               // break;
//            }
        }

    }

	logDynamic=true;//Registra em arquivo a dinamica interna do melhor individuo
	float teste=evaluate((*G).best);
	printf("\nMelhor individuo (%d). Fitness: %.5f",(*G).best, teste);

	(*G).write_pop((*G).best);

	fclose(file);
	
   

	struct rusage ru;
	//Leitura das informacoes do processo.
	getrusage(RUSAGE_SELF, &ru);
	printf("\nTempo: %.5f\n",	ru.ru_utime.tv_sec+ ru.ru_utime.tv_usec/1000000.0+
											ru.ru_stime.tv_sec+ ru.ru_stime.tv_usec/1000000.0);

	int quant_dinamica_1 = 0;
	//FILE *quant_dina = fopen("dinamica_quantidade.txt","r");
	//while( (fscanf(quant_dina,"%d\n", &quant_dinamica_1))!=EOF );

	//if(quant_dinamica_1 < 2125762){
	//	system("sleep 1");
	//	system("./a.out 1");
	//	quant_dinamica_1++;
	 // Se não alcançou a quantidade prevista de gerações, continua evolução


	//if((*G).geracao < (*G).geracoesPrevistas) // Se não alcançou a quantidade prevista de gerações, continua evolução
	//	system("./enviar.sh");
	
	delete(Iz);	
	delete(G);

	return 0;
}
