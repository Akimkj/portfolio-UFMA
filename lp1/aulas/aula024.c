#include <stdio.h>
#include <stdlib.h>
/*
    Aula 24 - operadores aritméticos
    adição        -> +
    subtração     -> -
    multiplicação -> *
    divisão       -> /

*/
int main() {
    int a = 10;
    int b = 2;
    printf("%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n\n", a, b, a / b);

    printf("%d / %f = %f", 10, 0.5, 10 / 0.5);


    return 0;
}