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
