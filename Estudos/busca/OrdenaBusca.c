#include <stdio.h>

void OrdenaInsercao(int v[], int l, int r){
    for(int i=l; i<r; i++){
        for(int j=l+1; j<r; j++){
            if(v[j]<v[j-1]) {
                int temp = v[j];
                v[j] = v[j-1];
                v[j-1]= temp;
            } 
        }
    }
}

int BB(int *v, int l, int r, int buscado){

    int meio = l + (r-l)/2;

    if (l>r)return -1;

    else if (v[meio]==buscado) return meio;

    else if(buscado > meio){
        return BB(v, meio+1, r, buscado);
    }

    else{
        return BB(v, l, meio-1, buscado);
    }

}

int main (){

    int vetor[10];

    for(int i = 0; i<9; i++){
        scanf("%d", &vetor[i]);
    }

    OrdenaInsercao(vetor, 0, 9);

    for(int i = 0; i<9; i++){
        printf("%d ", vetor[i]);
    }

    printf("\n");

    printf("%d", BB(vetor, 0, 9, 7));

    return 0;
}