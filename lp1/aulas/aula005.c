#include <stdio.h>
#include <stdlib.h>
/*Aula 5 - Criando variáveis e lendo números float*/
int main() {
    float numero;
    printf("Escreva um numero real: ");
    scanf("%f", &numero);

    printf("O numero digitado sem formatacao: %f \n", numero);
    printf("O numero digitado com formatacao: %.2f", numero);
    return 0;
}