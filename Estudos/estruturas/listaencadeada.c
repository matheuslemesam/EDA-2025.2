#include <stdio.h>
#include <stdlib.h>

// Este é o "molde" para o nosso baú (Nó)
struct No {
    int dado; // O "tesouro" que o nó guarda
    
    // A "próxima pista": um ponteiro para outro struct No
    struct No* proximo;
};

// Renomeando 'struct No' para apenas 'No' para ficar mais fácil de digitar
typedef struct No No; // alias de struct No

// Exemplo de uso
int main() {
    No *a = malloc(sizeof *a); // Aloca dinamicamente memória para um struct No e guarda o ponteiro em a
    No *b = malloc(sizeof *b);
    No *c = malloc(sizeof *c);
    if (!a || !b || !c) return 1; // checa se a aloc falhou
    a->dado = 10; // Acessa e atribui o campo dado dos nós alocados. logo, passa o valor 10 pro Nó A
    b->dado = 20;
    c->dado = 30;
    a->proximo = b; // Liga a para b (lista encadeada)
    b->proximo = c;
    c->proximo = NULL; // marca c como último Nó com NULL

    free(b);
    free(a);
    return 0;
}
/* 

O ponteiro 'head' é o nosso ponto de entrada.
Ele aponta para o primeiro nó.
   [head]
     |
     v
  +-------+    +-------+    +-------+
  | 10 |  *--->| 20 |  *--->| 30 |  *---> NULL
  +-------+    +-------+    +-------+
 (Nó 1)       (Nó 2)       (Nó 3)

 */