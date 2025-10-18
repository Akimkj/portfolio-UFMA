#include <stdlib.h>
#include <stdio.h>

// Conversão de tipo
int main() {
    int a = 10;
    int b = 20;
    float x = 3.141564;

    a = (int)x;
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %f\n\n", a, b, (float)a / b);

    return 0;
}