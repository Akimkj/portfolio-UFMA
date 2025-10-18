#include <stdio.h>
#include <stdlib.h>
/*Escreva um programa que leia um valor de despesa de restaurante, o valor da gorjeta (em porcentagem) e o número de pessoas para dividir a conta. Imprima o valor que cada um deve pagar. Assuma que a conta será dividida igualmente.*/
int main() {
    float despesa, valorPagar, gorjeta;
    int quantPessoas;
    printf("Informe, respectivamente:\n 1- a depesa do restaurante\n 2- a gorjeta(%%)\n 3- quantidade de pessoas a pagar\n");
    scanf("%f %f %d", &despesa, &gorjeta, &quantPessoas);

    gorjeta = gorjeta / 100;
    valorPagar = (despesa + (despesa * gorjeta)) / quantPessoas;

    printf("A quantidade a ser paga por cada pessoa deve ser de R$ %.2f", valorPagar);


    return 0;
}