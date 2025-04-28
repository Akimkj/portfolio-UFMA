#include <stdio.h>

int main() {
    int a, b, aux;
    printf("Digite os valores de 'a' e de 'b': ");
    scanf(" %d%d", &a, &b);

    aux = a;
    a = b;
    b = aux;
    
    printf("Valor de a: %d\n", a);
    printf("Valor de b: %d\n", b);

    return 0;
}