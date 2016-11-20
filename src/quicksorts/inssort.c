#include "inssort.h"
void insSort(TLista *lista,int *pos,int npos){
	int i, j, aux;
	for (i = 1; i < npos; i++) {
		aux = pos[i];
		j = i - 1;
		while(( j >= 0) && (lista->itens[aux].chave < lista->itens[pos[j]].chave)){
			pos[j + 1] = pos[j];
			j--;
		}
		pos[j+1] = aux;
	}
}

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
