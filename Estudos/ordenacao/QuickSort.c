#include <stdio.h>

#define Key(A) (A)
#define less(A,B)(Key(A)<Key(B))
#define exch(A,B){int T=A; A=B; B=T;}

int partition(int v[], int l, int r) {
    int pivot = v[l]; // Escolhe o primeiro elemento como pivô
    int i = l - 1;
    int j = r + 1;

    while (1) {
        // Encontra um elemento à esquerda que não é menor que o pivô
        do {
            i++;
        } while (less(v[i], pivot));

        // Encontra um elemento à direita que não é maior que o pivô
        do {
            j--;
        } while (less(pivot, v[j]));

        // Se os ponteiros se cruzaram, a partição está concluída
        if (i >= j) {
            return j;
        }

        // Troca os elementos que estão nos lugares errados
        exch(v[i], v[j]);
    }
}

// Função principal do QuickSort recursivo
void quickSort(int v[], int l, int r) {
    if (l < r) {
        // pi é o índice onde a partição foi dividida
        int pi = partition(v, l, r);

        // Ordena recursivamente a partição da esquerda
        quickSort(v, l, pi);
        // Ordena recursivamente a partição da direita
        quickSort(v, pi + 1, r);
    }
}