#include <stdio.h>
#include <stdlib.h>

typedef struct pilha {
    int *vetor;
    int topo;
    int n;
} pilha; 

pilha *Cria_pilha(int n){

    pilha *p = malloc(sizeof(pilha)); // Atribuir mem pra pikha
    p->vetor = malloc(n * sizeof(int)); // Atribuir mem pro vetor
    p->n = n; // (*p).n
    p->topo = 0; 

    return p;
}

int verificaPilha(pilha *p) {

    if (p->topo == p->n) return 1;

    else return 0;
}

void Empilha(pilha *p, int valor) {

    if (verificaPilha(p) == 1){
        p->vetor = realloc(p->vetor, 2*p->n*sizeof(int));
        p->n = p->n*2;
    }

    p->vetor[p->topo] = valor;
    p->topo ++;
}

int Desempilha(pilha *p, int *y) {

    if (p->topo == 0) return 0;
    p->topo --;
    *y = p->vetor[p->topo];

    return 1;
}

pilha *Remove_Pilha(pilha *p) {

    free(p->vetor);
    free(p);
    return;
}
