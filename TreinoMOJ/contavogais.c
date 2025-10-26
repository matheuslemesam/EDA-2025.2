#include <stdio.h>

int conta_vogais(char palavra[], int i){

    if (palavra[i] == '\0') {
        return 0;
    }

    if (palavra[i] == 'A' || palavra[i] == 'E' || palavra[i] == 'I' || palavra[i] == 'O' || palavra[i] == 'U') {
        return 1+conta_vogais(palavra, i+1);
    }

    else{
        return conta_vogais(palavra, i+1);
    }
}

int main (){

    char palavra[100];

    scanf("%s", palavra);

    int resultado = conta_vogais(palavra, 0);

    printf("%d\n", resultado);

    return 0;
}