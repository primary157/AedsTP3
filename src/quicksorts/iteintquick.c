#include "iteintquick.h"

void it_int_ordena(TLista *lista){
        int i, j;
	TPilha p;
	iniPilha(&p, lista->dir);

    particao(lista, &i,&j);
    if((j-lista->esq) > (lista->dir-i)){//Verifica se a partição da esquerda é a maior, ou seja é empilhada primeiro
        empilha(&p, lista->esq);
        empilha(&p, j);
        empilha(&p, i);
        empilha(&p, lista->dir);
    }else{// se não a da direira é empilhada primeiro
        empilha(&p, i);
        empilha(&p, lista->dir);
        empilha(&p, lista->esq);
        empilha(&p, j);
    }

    do{ // repte o processo enquanto houverem elementos a serem desempilhados
        lista->dir = desempilha(&p);
        lista->esq = desempilha(&p);
        particao(lista,&i,&j);
        if((j-lista->esq) > (lista->dir-i)){
            if(i<lista->dir && j>lista->esq){
                empilha(&p, lista->esq);
                empilha(&p, j);
                empilha(&p, i);
                empilha(&p, lista->dir);
            }else if(i<lista->dir){
                empilha(&p, i);
                empilha(&p, lista->dir);
            }else if(j>lista->esq){
                empilha(&p, lista->esq);
                empilha(&p, j);
            }
        }else{
            if(i<lista->dir && j>lista->esq){
                empilha(&p, i);
                empilha(&p, lista->dir);
                empilha(&p, lista->esq);
                empilha(&p, j);
            }else if(i<lista->dir){
                empilha(&p, i);
                empilha(&p, lista->dir);
            }else if(j>lista->esq){
                empilha(&p, lista->esq);
                empilha(&p, j);
            }
        }

    }while(p.top > 0);
    destroyTPilha(&p);// desaloca o vetor de indeces da pilha.


}

