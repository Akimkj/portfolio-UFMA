#include <stdio.h>

int main() {
    int num;
    while (1) {
        printf("Digite um inteiro (0 para sair): ");
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        (num  > 0) ? (printf("Positivo\n")) : (printf("Negativo\n"));
    }

    return 0;
}