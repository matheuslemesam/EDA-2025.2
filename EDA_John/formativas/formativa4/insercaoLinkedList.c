#include <stdio.h>
#include <stdlib.h>

/*
Uma função que insere um elemento x imediatamente antes da primeira ocorrência de um elemento y na lista encadeada. 
Se y não estiver na lista encadeada, x deve ser inserido ao final. O protótipo dessa função deve ser
*/

typedef struct celula {
    int dado;
   struct celula *prox;
} celula;

void insere_inicio (celula *le, int x){    

    celula *elementoX = malloc(sizeof(celula));
    elementoX->dado = x;
    elementoX->prox = le->prox;
    le->prox = elementoX;
}

void insere_antes (celula *le, int x, int y){
    
    if (le->prox == NULL){
        celula *elementoX = malloc(sizeof(celula));
        elementoX->dado = x;
        le->prox = elementoX;
        elementoX->prox = NULL;
        return 0;
    }

    else{
        celula *temp = le->prox;
        if(temp->dado == y) {
            celula *elementoX = malloc(sizeof(celula));
            elementoX->dado = x;
            le->prox = elementoX;
            elementoX->prox = temp;
            return 0;
            }
        insere_antes (le->prox, x, y);
    }
}
