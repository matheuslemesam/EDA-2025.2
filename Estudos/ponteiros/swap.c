#include <stdio.h>

void troca_numeros (int *a, int *b){

    int temp = *a;
    *a = *b;
    *b = temp;

}

int main() {

    int x = 10, y = 20;

    printf("x: %d, y: %d\n", x, y);

    troca_numeros(&x, &y);

    printf("x: %d, y: %d\n", x, y);

    return 0;
}

