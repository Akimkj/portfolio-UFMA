#include <stdio.h>

int main() {
    int num;
    printf("Digite um numero inteiro: ");
    scanf("%d", &num);

    (num < 0) ? (printf("negativo\n")) : ((num > 0) ? (printf("positivo\n")) : (printf("neutro\n")));

    return 0;
}