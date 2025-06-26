#include <stdio.h>

int main() {
    int a, *b, **c, ***d;
    printf("Escreva um número: ");
    scanf("%d", &a);
    b = &a;
    c = &b;
    d = &c;
    printf("a: %d\n", a);
    printf("dobro: %d\n", (*b) * 2);
    printf("triplo: %d\n", (**c) * 3);
    printf("quadruplo: %d\n", (***d) * 4);

    return 0;
}