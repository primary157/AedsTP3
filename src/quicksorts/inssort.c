#include "inssort.h"
void insercao(TLista *lista, int start, int end){
	int i;
	TItem aux;
	for(; start < end; start++){
		aux = lista->itens[start];
		i = start - 1;
		while ((i>=0) && (aux.chave < lista->itens[i].chave)) {
			lista->itens[i+1] = lista->itens[i];
			i--;
		}
		lista->itens[i+1] = aux;
	}
}
