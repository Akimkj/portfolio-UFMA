#include <stdio.h>

int main() {
    int num;
    printf("Digite um valor inteiro: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("\nnegativo\n");
    }
    else {
        if (num > 0) {
            printf("\npositivo\n");
        }
        else {
            printf("\nneutro\n");
        }
    }

    return 0;
}