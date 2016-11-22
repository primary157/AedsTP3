#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

typedef struct{
    unsigned long int *vecI;
    int top;
    int tam;
}TPilha;

void iniPilha(TPilha* p, int tam);
int empilha(TPilha* p, int a);
int desempilha(TPilha* p);
int destroyTPilha(TPilha* p);

#endif // PILHA_H_INCLUDED
