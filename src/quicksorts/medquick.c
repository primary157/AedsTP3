#include "medquick.h"
#define K 3
void med_particao(TLista *lista, int *i, int *j, int k){
	int *ipivo, c, med = 0, maior = -1, menor = -1;
	TItem pivo, aux;
	*i = lista->esq;
	*j = lista->dir;
	ipivo = (int*)malloc(k*sizeof(int));
	//encontra a media
	for (c = 0; c < k && c < (*j - *i + 1); c++) {
		ipivo[c] = rand()%(*j - *i + 1) + *i;
		med += lista->itens[ipivo[c]].chave;
	}
	med /= k;
	//encontra valores adjacentes a media no vetor
	for (c = 0; c < k && c < (*j - *i +1); c++) {
		if(lista->itens[ipivo[c]].chave > med){
			if(maior == -1){
				maior = ipivo[c];
			} else if(lista->itens[ipivo[c]].chave < maior){
				maior = ipivo[c];
			}
		} else if(lista->itens[ipivo[c]].chave < med){
			if(menor == -1){
				menor = ipivo[c];
			} else if(lista->itens[ipivo[c]].chave > menor){
				menor = ipivo[c];
			}
		}
	}
	//encontra valor mais proximo da media e o atribui a pivo
	free(ipivo);
	pivo = lista->itens[(lista->itens[maior].chave - med) < (med - lista->itens[menor].chave) ? maior : menor];
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
