#include <stdio.h>

void aumentar_valor(int* ptr) {
    *ptr += 10;
}

int main() {
    int a= 6;
    int *ptr1 = &a;
    printf("%d\n", a);
    aumentar_valor(ptr1);
    printf("%d\n", a);
    return 0;
}