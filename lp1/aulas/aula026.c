#include <stdio.h>
#include <stdlib.h>

/*Operador resto da divisão*/

int main() {
    int num1, num2;
    printf("Digite o valor inteiro do primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o valor inteiro do segundo numero: ");
    scanf(" %d", &num2);

    int restante = num1 % num2;
    printf("O resto da divisao: %d", restante);
}