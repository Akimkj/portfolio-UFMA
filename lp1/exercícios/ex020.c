#include <stdio.h>

void trocar_valores(int* ptr1, int* ptr2) {
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}
int main() {
    int a = 5, b = 2;
    int *ptr1 = &a, *ptr2 = &b;
    printf("a: %d, b: %d\n", *ptr1, *ptr2);
    trocar_valores(ptr1, ptr2);
    printf("a: %d, b: %d\n", *ptr1, *ptr2);
    return 0;
}