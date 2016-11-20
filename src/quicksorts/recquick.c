#include "recquick.h"
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
void ordena(TLista *lista){
	int i,j, sEsq, sDir;
	particao(lista,&i,&j);
	if(lista->esq < j){
		sDir = lista->dir;
		lista->dir = j;
		ordena(lista);
		lista->dir = sDir;
	}
	if(i < lista->dir){
		sEsq = lista->esq;
		lista->esq = i;
		ordena(lista);
		lista->esq = sEsq;
	}
}
/*
void ordena(TLista *lista){
	int i,j;
	particao(lista->esq,lista->dir,lista,&i,&j);
	if(lista->esq < j){
		_ordena(lista->esq, j, lista);
	}
	if(i < lista->dir){
		_ordena(i,lista->dir,lista);
	}
}
*/
