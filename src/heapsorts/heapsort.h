#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED
#include "../quicksorts/lista.h"
void heapSort(TLista *lista);
void refaz(TLista *lista);
void constroi(TLista *lista);
//Realmente necessários?
int retiraMax(TLista *lista, TItem *iMax);
int aumentaChave(int i, int nova_chave, TLista *lista);
void insere(TLista *lista,TItem item);

#endif
