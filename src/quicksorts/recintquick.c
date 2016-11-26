#include "recintquick.h"
void rec_int_ordena(TLista *lista){
	int i,j, sEsq, sDir;
	particao(lista,&i,&j);
	if((j - lista->esq) < (lista->dir - i)){
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
	else{
		if(i < lista->dir){
			sEsq = lista->esq;
			lista->esq = i;
			ordena(lista);
			lista->esq = sEsq;
		}
		if(lista->esq < j){
			sDir = lista->dir;
			lista->dir = j;
			ordena(lista);
			lista->dir = sDir;
		}
	}
}
