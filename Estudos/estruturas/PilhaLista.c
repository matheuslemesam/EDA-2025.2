#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int dado;
    struct pilha *prox;
} pilha;

pilha *criar_pilha(){

    pilha *topo = malloc(sizeof(pilha));
    topo->prox = NULL;

    return topo;
}

int verifica_pilha(pilha *topo){

    return (topo->prox == NULL);
}

void Empilha(pilha *topo, int x){

    pilha *p = malloc(sizeof(pilha));
    p->dado = x; 
    p->prox = topo->prox; 
    topo->prox = p;
}

int Desempilha(pilha *topo){

    if(verifica_pilha(topo)) return -1;

    pilha *temp = topo->prox;
    int dado = temp->dado;
    topo->prox = temp->prox;
    free(temp);

    return dado;
}