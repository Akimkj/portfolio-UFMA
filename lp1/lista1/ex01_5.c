#include <stdio.h>

int main() {
    int a, b, c, maior;
    scanf("%d %d %d", &a, &b, &c);
    maior = a;
    if (b > a && b > c) {
        maior = b;
    }
    if (c > a && c > b) {
        maior = c;
    }

    printf("O maior numero: %d", maior);

}