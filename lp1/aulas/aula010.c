#include <stdio.h>
#include <stdlib.h>
/*Lendo vários valores*/
int main() {
    int num1;
    char num2;
    float num3;
    printf("Digite um inteiro, um caracter e um float: ");
    scanf("%d %c %f", &num1, &num2, &num3);

    printf("%d %c %f", num1, num2, num3);
    return 0;
}