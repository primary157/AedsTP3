#include <stdio.h>
#include "../quicksorts/recquick.h"
#include "../quicksorts/itequick.h"
#include "../quicksorts/medquick.h"
#include "../quicksorts/insquick.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/resource.h>
typedef struct{
	double u;
	double s;
	double t;
}TIMES;
int confereSintaxeArquivoEntrada(FILE* file, int **n, int tam){
	while(!feof(file)){
		if(tam != 0){
			fscanf(file,"%d\n",&(*n)[--tam]);
		}
		else{
			printf("Mais N's do que escrito na primeira linha\n");
			return 0;
		}
	}
	if(tam !=0){
		printf("Menos N's do que escrito na primeira linha\n");
		return 0;
	}
	return 1;
}
TIMES printaTempoDecorrido(struct rusage *res,FILE *file,char *nome,TIMES tempos){
	//double utime, stime, total_time;
	TIMES times;
	if (getrusage(RUSAGE_SELF,res) != 0) {
		perror("getrusage failed\n");
	}
	times.u = (double)(*res).ru_utime.tv_sec + 1.e-6 * (double) (*res).ru_utime.tv_usec - tempos.u;
	times.s = (double)(*res).ru_stime.tv_sec + 1.e-6 * (double) (*res).ru_stime.tv_usec - tempos.s;
	times.t = times.u + times.s;
	fprintf(file,"%s User time %.3lf, System time %.3lf, Total time %.3lf\n",nome,times.u,times.s,times.t);
	return times;
	
}
int main(int argc, const char *argv[]){
	struct rusage resources;
	TIMES time_aux;
	time_aux.u = time_aux.s = time_aux.t = 0.0;

	FILE *inputfile, *outputfile;
	TItem *itens;
	int qntd_n_input, *n_input, i, j;
	TLista lista_aux;
	switch(argc){
		case 4:
			srand((unsigned int)atoi(argv[1]));
			if ((inputfile = fopen(argv[2],"r")) == NULL) {
				fprintf(stderr,"Nao foi possivel abrir arquivo de entrada %s\n",argv[2]);
				return 1;
			}
			else{
				if((outputfile = fopen(argv[3],"w")) == NULL){
					fprintf(stderr,"Nao foi possivel criar ou modificar arquivo de saida %s\n",argv[3]);
					fclose(inputfile);
					return 1;
				}else{
					fscanf(inputfile,"%d\n",&qntd_n_input);
					if((n_input = (int*)malloc(qntd_n_input*sizeof(int)))==NULL){		//Aloca espaço para n_input
						fprintf(stderr,"Nao foi possivel alocar espaco para n_input do tamanho %d\n",qntd_n_input);
						fclose(inputfile);
						fclose(outputfile);
						return 1;
					}
					if(!confereSintaxeArquivoEntrada(inputfile,&n_input,qntd_n_input)){
						fprintf(stderr,"Sintaxe de arquivo de entrada incorreta!\n");
						fclose(inputfile);
						fclose(outputfile);
						return 1;
					}
					fclose(inputfile);
					//AQUI QUE O PROGRAMA COMEÇA RODANDO OS QUICKSORTS DA VIDA
					//Primeiro alocando itens e usando esse valor inicial
					if((itens = (TItem*)malloc(n_input[0]*sizeof(TItem)))==NULL){		//Aloca espaço para itens
						fprintf(stderr,"Nao foi possivel alocar espaco para itens do tamanho %d\n",n_input[0]);
						fclose(inputfile);
						fclose(outputfile);
						return 1;
					}
					for (j = 0; j < n_input[0]; j++) {
						//Aqui gero os valores das N entradas da primeira instrução
						itens[j].chave = rand()%100000000;
					}
					time_aux = printaTempoDecorrido(&resources,outputfile,"Começo",time_aux);
					//Aqui ordeno a lista de entradas com cada quicksort e o tempo é calculado ao fim de cada ordenação
					//QuickSort 1
					
					initTLista(&lista_aux,itens,n_input[0]);	//reseto lista para estado inicial
					ordena(&lista_aux);
					
					time_aux = printaTempoDecorrido(&resources,outputfile,"QuickSort 1",time_aux);
					//QuickSort 2
					printf("Aqui\n");
					reinitTLista(&lista_aux,itens,n_input[0]);
					// usar funcao ordena(&lista_aux); referente ao QuickSort 2
					med_ordena(&lista_aux);

					time_aux = printaTempoDecorrido(&resources,outputfile,"QuickSort 2",time_aux);
					//QuickSort 3
					printf("Aqui\n");
					reinitTLista(&lista_aux,itens,n_input[0]);	//reseto lista para estado inicial
					// usar funcao ordena(&lista_aux); referente ao QuickSort 3
					ins_ordena(&lista_aux);

					time_aux = printaTempoDecorrido(&resources,outputfile,"QuickSort 3",time_aux);
					//QuickSort 4
					reinitTLista(&lista_aux,itens,n_input[0]);	//reseto lista para estado inicial
					// usar funcao ordena(&lista_aux); referente ao QuickSort 4

					time_aux = printaTempoDecorrido(&resources,outputfile,"QuickSort 4",time_aux);
					//QuickSort 5
					reinitTLista(&lista_aux,itens,n_input[0]);	//reseto lista para estado inicial
					// usar funcao ordena(&lista_aux); referente ao QuickSort 5
					it_ordena(&lista_aux);

					time_aux = printaTempoDecorrido(&resources,outputfile,"QuickSort 5",time_aux);
					//QuickSort 6
					reinitTLista(&lista_aux,itens,n_input[0]);	//reseto lista para estado inicial
					// usar funcao ordena(&lista_aux); referente ao QuickSort 6

					time_aux = printaTempoDecorrido(&resources,outputfile,"QuickSort 6",time_aux);
					//Fim do calculo de tempo de ordenação

					for (i = 1; i < qntd_n_input; i++) {
						if((itens = (TItem*)realloc(itens,n_input[i]*sizeof(TItem)))==NULL){		//Realoca espaço para itens
							fprintf(stderr,"Nao foi possivel realocar espaco para itens do tamanho %d\n",n_input[i]);
							fclose(inputfile);
							fclose(outputfile);
							return 1;
						}
						for (j = 0; j < n_input[i]; j++) {
							//Aqui gero os valores das N entradas de cada instrução
							itens[j].chave = rand()%100000000;
						}
						//Aqui ordeno a lista de entradas com cada quicksort e o tempo é calculado ao fim de cada ordenação
						//QuickSort 1
						reinitTLista(&lista_aux,itens,n_input[i]);
						ordena(&lista_aux);
							
						time_aux = printaTempoDecorrido(&resources,outputfile,"QuickSort 1",time_aux);
						//QuickSort 2
						printf("Aqui\n");
						reinitTLista(&lista_aux,itens,n_input[i]);
						// usar funcao ordena(&lista_aux); referente ao QuickSort 2
						med_ordena(&lista_aux);

						time_aux = printaTempoDecorrido(&resources,outputfile,"QuickSort 2",time_aux);
						//QuickSort 3
						printf("Aqui\n");
						reinitTLista(&lista_aux,itens,n_input[i]);
						// usar funcao ordena(&lista_aux); referente ao QuickSort 3
						ins_ordena(&lista_aux);

						time_aux = printaTempoDecorrido(&resources,outputfile,"QuickSort 3",time_aux);
						//QuickSort 4
						reinitTLista(&lista_aux,itens,n_input[i]);
						// usar funcao ordena(&lista_aux); referente ao QuickSort 4

						time_aux = printaTempoDecorrido(&resources,outputfile,"QuickSort 4",time_aux);
						//QuickSort 5
						reinitTLista(&lista_aux,itens,n_input[i]);	//reseto lista para estado inicial
						// usar funcao ordena(&lista_aux); referente ao QuickSort 5
						it_ordena(&lista_aux);

						time_aux = printaTempoDecorrido(&resources,outputfile,"QuickSort 5",time_aux);
						//QuickSort 6
						reinitTLista(&lista_aux,itens,n_input[i]);
						// usar funcao ordena(&lista_aux); referente ao QuickSort 6

						time_aux = printaTempoDecorrido(&resources,outputfile,"QuickSort 6",time_aux);
						//Fim do calculo de tempo de ordenação
					}
					free(itens);								//Desaloca espaço de itens
					destroyTLista(&lista_aux);						//Desaloca espaço de itens da lista
					//AQUI QUE O PROGRAMA TERMINA DE RODAR OS QUICKSORTS DA VIDA
					//AQUI QUE O PROGRAMA COMEÇA ESCREVENDO NO ARQUIVO DE SAIDA
					//A ser implementado ainda!!
					//AQUI QUE O PROGRAMA TERMINA DE ESCREVER NO ARQUIVO DE SAIDA E O FECHA!!
					free(n_input);							//Desaloca espaço de n_input
					fclose(outputfile);
					return 0;
				}
			}

		case 2:
			if(strcmp(argv[1],"-h") == 0 || strcmp(argv[1],"--help") == 0){
				printf("usage: RunQuickSorts <random seed> <input_file.txt> <output_file.txt>\nObs:\n\nrandom seed must be a decimal number\n");
				return 0;
			}
		default:
			fprintf(stderr,"Erro!! Esperado 3 argumentos. (use -h para obter ajuda)\n");
			return 1;
	}
}
