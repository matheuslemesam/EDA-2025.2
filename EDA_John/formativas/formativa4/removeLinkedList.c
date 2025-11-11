#include <stdio.h>
#include <stdlib.h>

// Definição da struct celula
typedef struct celula {
    int dado;
    struct celula *prox;
} celula;



void remove_depois (celula *p) {
    if (p == NULL || p->prox == NULL) {
        return;
    }

    celula *no_a_remover = p->prox;
    
    p->prox = no_a_remover->prox;
    
    free(no_a_remover);
}



void remove_elemento (celula *le, int x) {
    celula *p = le; 

    while (p != NULL && p->prox != NULL) {
    
        if (p->prox->dado == x) {
            remove_depois(p);
            return;
        }
        
        p = p->prox;
    }
}



void remove_todos_elementos (celula *le, int x) {
    celula *p = le;

    while (p != NULL && p->prox != NULL) {
        
        if (p->prox->dado == x) {
            remove_depois(p);
            
        } 
        
        else {
            p = p->prox;
        }

    }
}