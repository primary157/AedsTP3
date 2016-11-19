#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdlib.h>
typedef struct{
	int chave;
} TItem;
typedef struct{
	int esq, dir;
	TItem *itens;
} TLista;
void initTLista(TLista *lista,TItem *itens,int n);
void destroyTLista(TLista *lista);
void reinitTLista(TLista *lista,TItem *itens,int n);
#endif
