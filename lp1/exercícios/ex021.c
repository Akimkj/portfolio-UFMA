#include <stdio.h>

int main() {
    int a = 6;
    int *ptr1 = &a;
    printf("Valor de a: %d\nEndereço de a: %p\nValor que ponteiro aponta: %d\n", a, ptr1, *ptr1);
    return 0;
}