#include <stdio.h>

#define Key(A) (A)
#define less(A,B)(Key(A)<Key(B))

void merge(int *v, int l, int m, int r) {
    // aloca um vetor auxiliar para a intercalação
    int *aux = malloc(sizeof(int) * (r - l + 1));
    int i = l, j = m + 1, k = 0;

    // intercala os elementos de v[l..m] e v[m+1..r] no vetor aux[]
    while (i <= m && j <= r) {
        if (less(v[i], v[j])) {
            aux[k++] = v[i++];
        } else {
            aux[k++] = v[j++];
        }
    }

    // copia os elementos restantes da primeira metade, se houver
    while (i <= m) aux[k++] = v[i++];
    // copia os elementos restantes da segunda metade, se houver
    while (j <= r) aux[k++] = v[j++];

    // copia os elementos ordenados de aux[] de volta para v[]
    for (i = l, k = 0; i <= r; i++, k++) {
        v[i] = aux[k];
    }

    free(aux);
}

// função principal recursiva do Merge Sort
void MergeSort(int *v, int l, int r) {
    if (l >= r) return; // condição de parada: sub-vetor com 1 ou 0 elementos
    
    int m = l + (r - l) / 2; // calcula o meio para evitar overflow
    
    MergeSort(v, l, m);      // ordena a primeira metade
    MergeSort(v, m + 1, r);  // ordena a segunda metade
    merge(v, l, m, r);       // intercala as duas metades ordenadas
}