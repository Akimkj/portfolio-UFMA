#include <stdio.h>
#include <stdlib.h>
/*Uma empresa contrata um encanador a R$ 45,00 por dia. Faça um programa que solicite o número de dias trabalhados pelo encanador e imprima a quantia líquida que deverá ser paga, sabendo que são descontados 8% para imposto de renda.*/

int main() {
    int diasTrabalhados;
    printf("Informe a quantidade de dias trabalhados: ");
    scanf("%d", &diasTrabalhados);

    int valorBruto = diasTrabalhados * 45;
    float pagamento = valorBruto - (valorBruto * 0.08);

    printf("O valor a ser pago vai ser igual a R$ %.2f", pagamento);
    return 0;
}