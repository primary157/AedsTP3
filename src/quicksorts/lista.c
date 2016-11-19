#include "lista.h"
void initTLista(TLista *lista,TItem *itens,int n){
	int i;
	lista->itens = (TItem*)malloc(n*sizeof(TItem));
	for (i = 0; i < n; i++) {
		lista->itens[i] = itens[i];
	}
	lista->esq = 0;
	lista->dir = n-1;
}
void reinitTLista(TLista *lista,TItem *itens,int n){
	int i;
	lista->itens = (TItem*)realloc(lista->itens,n*sizeof(TItem));
	for (i = 0; i < n; i++) {
		lista->itens[i] = itens[i];
	}
	lista->esq = 0;
	lista->dir = n-1;
}
void destroyTLista(TLista *lista){
	free(lista->itens);
}
