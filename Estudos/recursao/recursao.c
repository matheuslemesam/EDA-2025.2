#include <stdio.h>

// Esta é a nossa função recursiva
int fatorial(int n) {
    
    // 1. O CASO BASE
    // Se n for 0, encontramos a "menor boneca" / "primeira pessoa".
    // A resposta é 1. Pare de chamar a si mesmo.
    if (n == 0) {
        return 1;
    } 
    
    // 2. O PASSO RECURSIVO
    // Se n não for 0, o problema ainda é "grande".
    // A resposta é n * (fatorial de um número menor, n-1)
    else {
        return n * fatorial(n - 1);
    }
}

int main() {
    int numero;
    
    scanf("%d", &numero);
    
    int resultado = fatorial(numero);
    
    // O resultado será 120
    printf("O fatorial de %d é %d\n", numero, resultado); 
    
    return 0;
}