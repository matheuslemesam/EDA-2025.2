#include <stdio.h>

/*

O que é Recursão?
Na forma mais simples: Recursão é uma função que chama a si mesma.

Pense nela como um problema que pode ser definido em termos de uma versão menor dele mesmo.

Analogia 1: As Bonecas Russas (Matryoshkas)
Imagine que você tem uma daquelas bonecas russas.

Você abre a boneca grande (a "função").

Dentro dela, você encontra... uma boneca um pouco menor (a "chamada recursiva").

Você abre essa boneca menor e encontra outra boneca, ainda menor.

Você repete esse processo...

Mas, e se isso continuasse para sempre? Você precisaria de bonecas infinitas. Isso não funciona.

Em algum momento, você abre uma boneca e encontra a última, a boneca sólida, que não se abre mais.

Em programação, isso é o "Caso Base" (Base Case).

Passo Recursivo (Recursive Step): Abrir uma boneca para encontrar uma boneca menor. É a função chamando a si mesma, mas com um problema "menor".

Caso Base (Base Case): Encontrar a última boneca sólida. É a condição que para a recursão.

Sem um caso base, sua função recursiva é como um conjunto infinito de bonecas russas. Ela nunca para e, em C, isso causa um erro chamado "Stack Overflow" (Estouro da Pilha).

*/

// Esta é a nossa função recursiva
int fatorial(int n) {
    
    // 1. O CASO BASE
    // Se n for 0, encontramos a "menor boneca".
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
    
    printf("O fatorial de %d é %d\n", numero, resultado); 
    
    return 0;
}