#include <stdio.h>
#include <stdlib.h>
/*Tipo primitivo double*/
int main() {
    double x = 535.32352636;
    // Diferente do tipo float, que usa 4 bytes na memória e tem uma precisão simples na hora de processar números reais, o tipo primitivo double serve para armazenar números reais com dupla precisão, ocupando 8 bytes na memória.
    printf("Tamanho do tipo de dado double: %d bytes", sizeof x);

    return 0;
}