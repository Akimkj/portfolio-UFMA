#include <stdio.h>
#include <stdlib.h>
/*Crie um programa em C que permita fazer a conversão cambial entre Reais e Dólares. Considere como taxa de câmbio US$1,0 = R$5,30. Leia um valor em Reais e mostre o correspondente em Dólares.*/
int main() {
    float real, dolar;
    printf("Digite o valor em reais: R$ ");
    scanf("%f", &real);

    dolar = real / 5.30;

    printf("O valor em dolares fica: US$ %.2f\n", dolar);

    return 0;
}