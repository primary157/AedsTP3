#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/resource.h>
int confere_sintaxe_arquivo_entrada(FILE* file){
	int tam;
	int *n;
	fscanf(file,"%d\n",&tam);
	n = (int*)malloc(tam*sizeof(int));
	while(!feof(file)){
		if(tam != 0){
			fscanf(file,"%d\n",&n[--tam]);
		}
		else{
			printf("sera?\n");
			return 0;
		}
	}
	return 1;
}
int main(int argc, const char *argv[]){
	struct rusage resources;
	double utime, stime, total_time;
	switch(argc){
		case 4:
			srand((unsigned int)atoi(argv[1]));
			FILE *inputfile, *outputfile;
			if ((inputfile = fopen(argv[2],"r")) == NULL) {
				fprintf(stderr,"Nao foi possivel abrir arquivo de entrada %s\n",argv[2]);
				return 1;
			}
			else{
				if((outputfile = fopen(argv[3],"w")) == NULL){
					fprintf(stderr,"Nao foi possivel criar ou modificar arquivo de saida %s\n",argv[3]);
					return 1;
				}else{
					if(!confere_sintaxe_arquivo_entrada(inputfile)){
						fprintf(stderr,"Sintaxe de arquivo de entrada incorreta!\n");
						return 1;
					}
					if (getrusage(RUSAGE_SELF,&resources) != 0) {
						perror("getrusage failed\n");
					}
					utime = (double)resources.ru_utime.tv_sec + 1.e-6 * (double) resources.ru_utime.tv_usec;
					stime = (double)resources.ru_stime.tv_sec + 1.e-6 * (double) resources.ru_stime.tv_usec;
					total_time = utime + stime;
					printf("User time %.3lf, System time %.3lf, Total time %.3lf\n",utime,stime,total_time);
					fclose(inputfile);
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
