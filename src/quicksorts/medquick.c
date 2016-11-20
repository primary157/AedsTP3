#include "medquick.h"
#define K 3
void med_particao(TLista *lista, int *i, int *j, int k){
	int ipivo = 0, c;
	TItem pivo, aux;
	*i = lista->esq;
	*j = lista->dir;
	for (c = 0; c < k; c++) {
		ipivo += rand()%(lista->sz);
	}
	pivo = lista->itens[ipivo/k];
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
void ordena(TLista *lista){
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
