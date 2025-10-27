#include <stdio.h>

#define Key(A) (A)
#define less(A,B)(Key(A)<Key(B))
#define exch(A,B){int T=A; A=B; B=T;}
#define cmpexch(A,B){if(less(B,A)) exch(A,B);}

void InsertionSortSlow(int v[], int l, int r){

    for(int i=l+1; i<=r; i++){
        for(int j=i; j>l; j--)
            cmpexch(v[j-1], v[j]);
    }

}

int main() {

    int v[10];
    int n = 0;

    while(scanf("%d", &v[n]) != EOF){
        n++;
    }

    InsertionSortSlow(v, 0, n-1);

    printf("\n");

    for(int i=0; i<n; i++)
        printf("%d ", v[i]);    

    printf("\n");
    
    return 0;
}