#include <stdio.h>

// Definição da struct celula
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime (celula *le) {
    celula *p;
    
    for (p = le->prox; p != NULL; p = p->prox) {
        printf("%d -> ", p->dado);
    }
    printf("NULL\n");
}

// Forma recursiva
void imprime_rec (celula *le) {
    // Caso Base
    if (le->prox == NULL) {
        printf("NULL\n");
        return;
    }
    
    // Passo Recursivo
    printf("%d -> ", le->prox->dado);
    imprime_rec(le->prox);
}