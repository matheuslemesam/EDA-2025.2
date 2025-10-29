#include <stdio.h>

int BuscaBinariaRecursiva(int *v, int l, int r, int buscado){

    if (l > r) {
        return l; // O item não foi encontrado, caso base da recursão
    }

    int meio = (l+r)/2; // divide o vetor

    if(buscado == v[meio]) // se o nmr buscado é igual ao elemento no índice do meio
        return meio;

    else if(buscado > v[meio])
        return BuscaBinariaRecursiva(v, meio+1, r, buscado); // se o buscado for maior, chama a busca redividindo o vetor para cima

    else
        return BuscaBinariaRecursiva(v, l, meio-1, buscado); // se o buscado for menor, chama a busca redividindo o vetor para baixo
        
}

int main() {

    int nVet, nBusc;

    scanf("%d %d", &nVet, &nBusc);

    int vetorN[nVet];
    int vetorB[nBusc];

    for(int i=0; i<nVet; i++){
        scanf("%d ", &vetorN[i]);
    }

    for(int i=0; i<nBusc; i++){
        scanf("%d ", &vetorB[i]);
    }

    for(int i=0; i<nBusc; i++)
    printf("%d\n", BuscaBinariaRecursiva(vetorN, 0, nVet-1, vetorB[i]));

    return 0;
}