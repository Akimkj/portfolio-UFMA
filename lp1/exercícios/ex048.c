#include <stdio.h>
#include <stdlib.h>
/*Faça um programa em C para trocar o valor de duas variáveis inteiras sem utilizar nenhuma variável auxiliar.*/
int main() {
    int a, b;
    printf("Digite o valor de a: ");
    scanf("%d", &a);
    printf("Digite o valor de b: ");
    scanf(" %d", &b);
    // 6 e 4
    a += b; // a = 10 b = 4
    b = a - b; // a = 10 b = 6
    a -= b; // b = 6 a = 4

    printf("Valor de a: %d\nValor de b: %d\n", a, b);

    return 0; 
}