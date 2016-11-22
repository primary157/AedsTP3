#include "pilha.h"

void iniPilha(TPilha* p, int tam){
    p->top = 0;
    p->tam = tam;
    p->vecI = (int*)malloc((tam*4)*sizeof(int));
}
int empilha(TPilha* p, int a){
    if(p->top == p->tam)
        return 0;
    p->vecI[p->top++] = a;
    return 1;
}
int desempilha(TPilha* p){
    if(p->top == 0)
        return 0;
    return p->vecI[--p->top];
}

int destroyTPilha(TPilha* p){
    free(p->vecI);
    return 1;
}
