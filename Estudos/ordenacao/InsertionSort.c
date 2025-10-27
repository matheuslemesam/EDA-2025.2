#include <stdio.h>

#define Key(A) (A)
#define less(A,B)(Key(A)<Key(B))
#define exch(A,B){int T=A; A=B; B=T;}
#define cmpexch(A,B){if(less(A,B)) exch(A,B);}

void InsertionSort(int *v, int l, int r){

    for(int i=r; i>l; i--){
        cmpexch(v[i-1], v[i]);
    }

    for(int i = l+2; i<=r; i++){
        int j = i;
        int temp = v[j];
        while(less(temp, v[j-1])){
            v[j] = v[j-1];
            j--;
        }
        v[j] = temp;
    }
}

int main() {

    int v[10];
    int n = 0;

    while(scanf("%d", &v[n]) != EOF){
        n++;
    }

    InsertionSort(v, 0, n-1);

    printf("\n");

    for(int i=0; i<n; i++)
        printf("%d ", v[i]);    

    printf("\n");

    return 0;
}