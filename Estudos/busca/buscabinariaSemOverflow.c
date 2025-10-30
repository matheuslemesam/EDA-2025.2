#include <stdio.h>

int BuscaBinariaRecursiva(int *v, int l, int r, int buscado){

    if (l > r) {
        return -1; // O item não foi encontrado, caso base da recursão
    }

    int meio = l+(r-l)/2; // divide o vetor, previnir overflow

    if(buscado == v[meio]) // se o nmr buscado é igual ao elemento no índice do meio
        return meio;

    else if(buscado > v[meio])
        return BuscaBinariaRecursiva(v, meio+1, r, buscado); // se o buscado for maior, chama a busca redividindo o vetor para cima

    else
        return BuscaBinariaRecursiva(v, l, meio-1, buscado); // se o buscado for menor, chama a busca redividindo o vetor para baixo
}