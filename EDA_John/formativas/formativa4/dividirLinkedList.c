#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void divide_lista (celula *l, celula *l1, celula *l2) {
    celula *p_l = l->prox;
    celula *p1 = l1;
    celula *p2 = l2;
    celula *proximo_no = NULL;

    while (p_l != NULL) {

        proximo_no = p_l->prox;
        
        if (p_l->dado % 2 == 0) {
            p2->prox = p_l;
            p2 = p_l;
        } 
        
        else {
            p1->prox = p_l;
            p1 = p_l;
        }
        
        p_l = proximo_no;
        
    }

    p1->prox = NULL;
    p2->prox = NULL;
    
    l->prox = NULL;
}