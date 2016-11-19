#ifndef RECQUICK_H_INCLUDED
#define RECQUICK_H_INCLUDED
typedef struct{
	int chave;
} TItem;
typedef struct{
	int esq, dir;
	TItem *itens;
} TLista;
void initTLista(TLista *lista,TItem *itens,int n);
void particao(TLista *lista, int *i, int *j); //iteradores i e j são criados dentro de ordena!!
void ordena(TLista *lista);
void _ordena(int esq, int dir, TLista *lista);
#endif
