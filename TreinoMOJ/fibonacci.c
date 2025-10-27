#include <stdio.h>

long int memorizado[81] = {0};

long int fibonacci(int n){
    
    if (n == 1 || n == 2)
        return 1;
    
    if (memorizado[n] != 0)
        return memorizado[n];
    
    memorizado[n] = fibonacci(n-1) + fibonacci(n-2);
    return memorizado[n];
}

int main() {
    
    int n;
    scanf("%d", &n);
    
    long long int resultado = fibonacci(n);
    
    printf("%lld\n", resultado);
    
    return 0;
}