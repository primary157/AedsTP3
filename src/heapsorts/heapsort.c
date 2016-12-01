#include "heapsort.h"
void heapSort(TLista *lista){
	TItem aux;
	constroi(lista);
	while( lista->dir > 1){
		aux = lista->itens[1];
		lista->itens[1] = lista->itens[lista->dir];
		lista->itens[lista->dir--] = aux;
		refaz(lista);
	}
}
void refaz(TLista *lista){
	int j, i = lista->esq;
	TItem aux;
	j = i * 2;
	aux = lista->itens[i];
	while (j <= lista->dir) {
		if (j < lista->dir && lista->itens[j].chave < lista->itens[j+1].chave) {
			j++;
		}
		if(aux.chave >= lista->itens[j].chave){
			break;
		}
		lista->itens[i] = lista->itens[j];
		i = j;
		j = i * 2;
	}
	lista->itens[i] = aux;
}
void constroi(TLista *lista){
	lista->esq = lista->sz/2;
	while (lista->esq > 0) {
		refaz(lista);
		lista->esq--;
	}
}
