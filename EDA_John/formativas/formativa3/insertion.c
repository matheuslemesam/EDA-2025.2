#include <stdio.h>

void insertion_sort(int vetor[], int tamanho){
    for(int i = 1; i < tamanho; i++){
        int chave = vetor[i];
        int j = i - 1;
        
        while(j >= 0 && vetor[j] > chave){
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

int main (){

    int vetor[50000];

    int n=0;

    while(scanf("%d", &vetor[n]) != EOF){ //ctrl D
        n++;
    }

    insertion_sort(vetor, n);

    for(int a=0; a<n; a++)
        printf("%d ", vetor[a]);

    return 0;
}