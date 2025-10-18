#include <stdio.h>

int main() {
    int num;
    while (1) {
        printf("Digite um inteiro (digite 0 para encerrar): ");
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        if (num > 0) {
            printf("Valor positivo!\n");
        }
        else {
            printf("Valor negativo!\n");
        }
    }
    return 0;
}