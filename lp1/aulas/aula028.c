#include <stdio.h>
#include <stdlib.h>
/*Operador de decremento*/
int main() {
    int contador = 10;
    while (contador >= 1) {
        printf("%d\n", contador);
        --contador;
    }
}