#include <stdio.h>

int main() {

    int a = 30; //declara a = 30;

    int *ptr; //declara ponteiro ptr 
    
    ptr = &a; //atribui o valor que está no endereço de a (30)

    printf("printar a (30), a: %d\n", a); //printar a (30)

    printf("printar endereço de memória de a, &a: %p\n", (void*)&a); //printar endereço de memória de a 

    printf("printar o endereço que o ptr aponta, ptr: %p\n", (void*)ptr); //printar o endereço ptr

    printf("printar endereço do ponteiro ptr, &ptr: %p\n", (void*)&ptr); //printar endereço do ponteiro ptr

    printf("printar valor de a (30), *ptr: %d\n", *ptr); //printar valor de a (30)

    return 0;
}