#include <stdio.h>

void trocar(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

int main() {

    int a = 4, b = 5;
    trocar(&a, &b);
    printf("%d %d", a, b);
    return 0;
}