#include <stdio.h>

// Definição da struct celula
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

// Forma iterativa
celula *busca (celula *le, int x) {
    celula *p;
    for (p = le->prox; p != NULL; p = p->prox) {
        if (p->dado == x) {
            return p;
        }
    }
    
    return NULL;
}

// Forma recursiva
celula *busca_rec (celula *le, int x) {
    // Caso Base
    if (le->prox == NULL) {
        return NULL;
    }

    // Caso Busca
    if (le->prox->dado == x) {
        return le->prox;
    }

    // Passo Recursivo
    return busca_rec(le->prox, x);
}