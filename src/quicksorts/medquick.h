#ifndef MEDQUICK_H_INCLUDED
#define MEDQUICK_H_INCLUDED
#include "lista.h"
void med_particao(TLista *lista, int *i, int *j, int k); //iteradores i e j são criados dentro de med_ordena!!
void med_ordena(TLista *lista);	//Função ordena q chama med_partição


#endif

