#include <stdio.h>

int main() {
    int num;
    printf("Digite um valor inteiro: ");
    scanf("%d", &num);

    printf("Resultado logico: %d\n", num >= 0);

    if (-3) {
        printf("maior ou igual a 0");
    }
    else {
        printf("negativo");
    }
    return 0;
}