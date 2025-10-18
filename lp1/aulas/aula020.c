#include <stdio.h>
#include <stdlib.h>
/*Aula 20 - tamanho de um float*/
int main() {
    //a junção short float e long long float não é válida
    float x = 214748367.4842;
    printf("O tamanho do tipo float: %d bytes\n", sizeof x);
    printf("\n%f\n", x);
    x++;
    printf("\n%f\n", x);

    return 0;
}