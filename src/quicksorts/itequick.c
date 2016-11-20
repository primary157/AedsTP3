#include "itequick.h"
/*
void particao(TLista *lista, int *i, int *j){
	TItem pivo, aux;
	*i = lista->esq;
	*j = lista->dir;
	pivo = lista->itens[(*i+*j)/2];
	do {
		while (pivo.chave > lista->itens[*i].chave) {
			(*i)++;
		}
		while (pivo.chave < lista->itens[*j].chave) {
			(*j)--;
		}
		if (*i <= *j) {
			aux = lista->itens[*i];
			lista->itens[*i] = lista->itens[*j];
			lista->itens[*j] = aux;
			(*i)++;
			(*j)--;
		}
	} while (*i <= *j);
}
*/
void it_ordena(TLista *lista){
	int i, j, k = 0;
	int *vecEsq, *vecDir;
	vecEsq = (int*)malloc(lista->dir*sizeof(int));
	vecDir = (int*)malloc(lista->dir*sizeof(int));
	do{
		particao(lista, &i, &j); // divide a primeira partição em esq e dir
		vecEsq[k] = i; //quarda os valores onde foi quebrado na esqueda
		vecDir[k] = lista->dir; // guarda os valores onde foi quedrado na direita
		k++;
		lista->dir = j; // a direita recebe o ultimo valor de j...
	}while(j>0); // vai percorrer sempre a esqueda enquanto o j não tiver chegado ao final
	k--;// desincrementa 1 no contador para não pegar lixo;
	// fará o próximo while, de trás para frente percorrendo o vertor de liitações de direita e esquerda
	while(k>=0){ // enquando houver limitações nos vetores de esq e dir faz
		lista->esq = vecEsq[k]; // esqueda pega a parte limita pela esqueda onde ainda não foi particionada
		lista->dir = vecDir[k]; // direita recebe a parte limitada pea direita que ainda não foi particionada
		particao(lista, &i, &j); // particiona a área delimitada
		while(j>lista->esq){
		 // se o j, não tiver atingindo o valor da esqueda quer dizer que há vetores a
		// serem percorridos na esqueda, logo como o while de cima ele percorre sempre à esquerda
		    particao(lista, &i, &j); // particona e quarda as limitações caso haja vetores à direita ainda não particionados.
		    vecEsq[k] = i;
		    vecDir[k] = lista->dir;
		    k++; // incrementa o contador dizendo que há mais partições a seres reparticionadas.
		    lista->dir = j;
		}
        	k--; // desincrementa o contador de limitações;
	}
	free(vecEsq);
	free(vecDir);
}
