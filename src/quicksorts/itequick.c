#include "itequick.h"
/*
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
*/
void it_ordena(TLista *lista){
	int i, j;

	TPilha p;
	iniPilha(&p, lista->dir);

    particao(lista, &i,&j);
    empilha(&p, lista->esq); //empilha primeiro a partição esqueda
    empilha(&p, j);
    empilha(&p, i); // logo a da direita é processada primeiro nesse caso. 
    empilha(&p, lista->dir);
    do{
        lista->dir = desempilha(&p); // desempilha a partição limitado por esqueda e direita
        lista->esq = desempilha(&p);
        particao(lista,&i,&j);
        if(i<lista->dir && j>lista->esq){ // verifica se não chegou ao final de nenhum lado da lista
            empilha(&p, lista->esq); // logo empilha a partição da direita e esqueda
            empilha(&p, j);
            empilha(&p, i);
            empilha(&p, lista->dir);
        }else if(i<lista->dir){ // verifica se chegou ao final da lista na esqueda
            empilha(&p, i); // logo empilha apenas a partição da direita já que a esquerda chegou ao final
            empilha(&p, lista->dir);
        }else if(j>lista->esq){ // verifica se chegou ao final da lista na direita
            empilha(&p, lista->esq); // logo empilha apenas a partição da esqueda, já que a direita chegou ao final
            empilha(&p, j);
        }// caso contrário, direita e esqueda tiver chegado ao final, não fz nada
    }while(p.top > 0); // enquanto houverem partições continua particionando ou desempilhando. 
    destroyTPilha(&p);
}
