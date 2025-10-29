#include <stdio.h>

#define Key(A) (A)
#define less(A,B)(Key(A)<Key(B))
#define exch(A,B) {int T=A; A=B; B=T;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

void SelectionSort(int *v, int l, int r){
    if (l >= r) {
        return;
    }
    
    for(int i = l + 1; i <= r; i++){
        cmpexch(v[l], v[i]);
    }

    SelectionSort(v, l + 1, r);
}

int main(){
    



    return 0;
} 