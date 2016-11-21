#include "iteintquick.h"

void particao(TLista *lista, int *i, int *j){
	TItem pivo, aux;
	int b;
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

void ordena(TLista *lista){
    int i, j, top = 0;
	int *stack;
	stack = (int*)malloc(lista->dir*(4)*sizeof(int));
    particao(lista, &i,&j);
    //VERIFICA A ORDEM EM QUE DEVE SER EMPILHADA.
    //A MAIOR PARTIÇÃO É EMPILHADA PRIMEIRO
    if((j - lista->esq) >= ( lista->dir - i)){// VERIFICA SE A DIREITA É MENOR QUE A PARTIÇÃO DA ESQUEDA
        stack[top++] = lista->esq; // CASO SIM, EMPILHA PRIMEIRO A ROTA DA ESQUEDA
        stack[top++] = j; // LIMITADA POR ESQ - J
        stack[top++] = i; // DEPOIS EMPILHA A MENOR ROTA, LIMITADA POR I - DIR
        stack[top] = lista->dir;
    }else{
        stack[top++] = i; // CASO A MAIOR ROTA SEJA A DIREITA
        stack[top++] = lista->dir; // EMPILHA A MAIOR ROTA, LIMITADA POR I - DIR
        stack[top++] = lista->esq; // EMPILHA A MENOR ROTA LIMITADA POR ESQ - J
        stack[top] = j;
    }

	do{
        lista->dir = stack[top--]; //PEGA O TOPO DO PILHA, OU SEJA, A ROTA DA DIREITA
        lista->esq = stack[top--]; // PEGA O SEGUNDO TOPO, OU SEJA, A ROTA DA ESQUEDA
        particao(lista, &i, &j); // PARTICONA A MENOR ROTA
        if((j - lista->esq) >= ( lista->dir - i)){ // VERIFICA SE A ROTA PARTICONADA É MAIOR NA ESQUERDA OU DIREITA
            if(i == lista->dir && j != lista->esq ){ // SE A DERITA CHEGOU AO FINAL, MAS TEM ELEMENTOS NA ESQUERDA
                stack[++top] = lista->esq; // EMPLIHA A ROTA LIMITADA PELA ESQUERDA E J
                stack[++top] = j;
            }else if( i != lista->dir && j == lista->esq){ // SE A ESQUERDA CHEGOU AO FINAL, MAS TEM ELEMENTOS A DIREITA
                stack[++top] = i; // EMPILHA A ROTA LIMITADA PELO I E A DIREITA
                stack[++top] = lista->dir;
            }else if ((i != lista->dir) && (j != lista->esq)){ // SE NÃO CHEGOU NO FINAL NEM A ESQUQEDA NEM NA DIREITA
                stack[++top] = lista->esq; // ESPILHA PRIMEIRO A ROTA MAIOR, NO CASO A ESQUEDA
                stack[++top] = j;
                stack[++top] = i; // DEPOIS A MENOR, NO CASO A DIREITA;
                stack[++top] = lista->dir;
            }
        }else{ // CASO A MAIOR ROTA SEJA A DA DIREITA
            if(i == lista->dir && j != lista->esq ){ // SE A DIREITA CHEGOU AO FINAL, MAS A ESQUEDA NÃO;
                stack[++top] = lista->esq; // EMPILHA A ROTA DA ESQUEDA
                stack[++top] = j;
            }else if( i != lista->dir && j == lista->esq){ // SE A ESQUEDA CHEGOU AO FINAL, MAS A DIREITA NÃO
                stack[++top] = i;
                stack[++top] = lista->dir;
            }else if ((i != lista->dir) && (j != lista->esq)){ // SE NEM A ESQUEDA NEM A DIREITA CHEGOU AO FINAL
                stack[++top] = i; // EMPILHA PRIMEIRO A ROTA DA DIREITA MAIOR, OU SEJA LIMITADA PELO I - DIREITA
                stack[++top] = lista->dir;
                stack[++top] = lista->esq; // EMPILHA A ROTA DA ESQUERDA MENOR, LIMITADA PELA ESQ - J
                stack[++top] = j;
            }
        }
	}while(top>0); // ENQUANTO HOUVER ELEMENTOS NA PILHA CONTINUA O LOOP.

}
