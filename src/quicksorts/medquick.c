#include "medquick.h"
#define K 3
void med_particao(TLista *lista, int *i, int *j, int k){
	int *ipivo;
	TItem pivo, aux;
	*i = lista->esq;
	*j = lista->dir;
	ipivo = (int*)malloc(k*sizeof(int));
	//ordena ipivo pelas chaves em lista
	insSort(lista,ipivo,k);
	//Pega o do meio
	pivo = lista->itens[ipivo[(k/2)+1]];
	free(ipivo);
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
void med_ordena(TLista *lista){
	int i,j, sEsq, sDir;
	med_particao(lista,&i,&j,K);
	if(lista->esq < j){
		sDir = lista->dir;
		lista->dir = j;
		med_ordena(lista);
		lista->dir = sDir;
	}
	if(i < lista->dir){
		sEsq = lista->esq;
		lista->esq = i;
		med_ordena(lista);
		lista->esq = sEsq;
	}
}
