#include <stdio.h>
#include <stdlib.h>

// Definição do Nó 
typedef struct No {
    int dado;
    struct No* proximo;
} No;


// Função insere_no_inicio 
void insere_no_inicio(No** cabeca_ref, int novo_dado) {
    No* novo_no = (No*) malloc(sizeof(No));
    if (novo_no == NULL) {
        printf("Erro de alocação de memória!\n");
        return;
    }
    novo_no->dado = novo_dado;
    novo_no->proximo = (*cabeca_ref);
    (*cabeca_ref) = novo_no;
}

// inserir no final
void insere_no_fim(No** cabeca_ref, int novo_dado) {
    No* novo_no = (No*) malloc(sizeof(No));
    if (!novo_no) {
        printf("Erro de alocação de memória!\n");
        return;
    }
    novo_no->dado = novo_dado;
    novo_no->proximo = NULL;

    if (*cabeca_ref == NULL) {
        *cabeca_ref = novo_no;
        return;
    }

    No* atual = *cabeca_ref;
    while (atual->proximo != NULL)
        atual = atual->proximo;
    atual->proximo = novo_no;
}

// inserir depois de um nó (por valor)
int insere_depois_de_valor(No* cabeca, int valor, int novo_dado) {
    No* atual = cabeca;
    while (atual != NULL && atual->dado != valor)
        atual = atual->proximo;
    if (atual == NULL) return 0; // não encontrado

    No* novo_no = (No*) malloc(sizeof(No));
    if (!novo_no) return 0;
    novo_no->dado = novo_dado;
    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
    return 1;
}

// inserir em posição (0-index). retorna 1 sucesso, 0 fracasso.
int insere_em_posicao(No** cabeca_ref, int pos, int novo_dado) {
    if (pos < 0) return 0;
    if (pos == 0) {
        insere_no_inicio(cabeca_ref, novo_dado);
        return 1;
    }
    No* atual = *cabeca_ref;
    for (int i = 0; atual != NULL && i < pos - 1; i++)
        atual = atual->proximo;
    if (atual == NULL) return 0; // posição além do tamanho

    No* novo_no = (No*) malloc(sizeof(No));
    if (!novo_no) return 0;
    novo_no->dado = novo_dado;
    novo_no->proximo = atual->proximo;
    atual->proximo = novo_no;
    return 1;
}

// remover por valor (remove primeira ocorrência). retorna 1 sucesso, 0 não encontrado.
int remover_por_valor(No** cabeca_ref, int valor) {
    No* atual = *cabeca_ref;
    No* anterior = NULL;

    while (atual != NULL && atual->dado != valor) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) return 0; // não encontrado

    if (anterior == NULL) // é o primeiro nó
        *cabeca_ref = atual->proximo;
    else
        anterior->proximo = atual->proximo;

    free(atual);
    return 1;
}

// remover por posição (0-index). retorna 1 sucesso, 0 fracasso.
int remover_por_posicao(No** cabeca_ref, int pos) {
    if (pos < 0 || *cabeca_ref == NULL) return 0;
    No* atual = *cabeca_ref;

    if (pos == 0) {
        *cabeca_ref = atual->proximo;
        free(atual);
        return 1;
    }

    No* anterior = NULL;
    for (int i = 0; atual != NULL && i < pos; i++) {
        anterior = atual;
        atual = atual->proximo;
    }
    if (atual == NULL) return 0; // posição inválida

    anterior->proximo = atual->proximo;
    free(atual);
    return 1;
}

// liberar toda a lista
void liberar_lista(No** cabeca_ref) {
    No* atual = *cabeca_ref;
    while (atual != NULL) {
        No* prox = atual->proximo;
        free(atual);
        atual = prox;
    }
    *cabeca_ref = NULL;
}

// Função imprimirLista 
void imprimirLista(No* cabeca) {
    No* atual = cabeca;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d -> ", atual->dado);
        atual = atual->proximo;
    }
    printf("NULL\n");
}


// Função principal
int main() {
    // 1. A caça ao tesouro começa vazia. O 'head' aponta para o FIM (NULL).
    No* head = NULL; 

    // Inserções de exemplo
    insere_no_inicio(&head, 10);
    insere_no_inicio(&head, 20);
    insere_no_inicio(&head, 30); // 30 -> 20 -> 10
    imprimirLista(head);

    insere_no_fim(&head, 5);     // 30 -> 20 -> 10 -> 5
    imprimirLista(head);

    insere_depois_de_valor(head, 20, 25); // insere 25 depois do 20: 30 -> 20 -> 25 -> 10 -> 5
    imprimirLista(head);

    insere_em_posicao(&head, 2, 99); // posição 2 (0-index): 30,20,99,...
    imprimirLista(head);

    // Remoções de exemplo
    remover_por_valor(&head, 99); // remove 99
    imprimirLista(head);

    remover_por_posicao(&head, 0); // remove primeiro (30)
    imprimirLista(head);

    // liberar memória
    liberar_lista(&head);
    imprimirLista(head); // deve mostrar NULL

    return 0;
}