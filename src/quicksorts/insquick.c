#include "insquick.h"
#define M 10
void ins_particao(TLista *lista, int *i, int *j){
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
void ins_ordena(TLista *lista){
	int i,j, sEsq, sDir;
	if(lista->dir - lista->esq > M){
		ins_particao(lista,&i,&j);
		if(lista->esq < j){
			sDir = lista->dir;
			lista->dir = j;
			ins_ordena(lista);
			lista->dir = sDir;
		}
		if(i < lista->dir){
			sEsq = lista->esq;
			lista->esq = i;
			ins_ordena(lista);
			lista->esq = sEsq;
		}
	}
	else{
		insercao(lista,lista->dir,lista->esq);
	}
}

