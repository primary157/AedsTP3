#include "recquick.h"
void particao(int esq, int dir, TLista *lista, int *i, int *j){
	TItem pivo, aux;
	*i = esq;
	*j = dir;
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
void _ordena(int esq, int dir, TLista *lista){
	int i,j;
	particao(esq,dir,lista,&i,&j);
	if(esq < j){
		_ordena(esq, j, lista);
	}
	if(i < dir){
		_ordena(i,dir,lista);
	}
}
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
