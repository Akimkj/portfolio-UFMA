#include <stdio.h>
#include <stdlib.h>
/*Aula 16 - operador sizeof

sizeof x ou sizeof (int)
*/
int main() {
    float x = 55677.8446;
    printf("Tamanho na memoria do tipo de dado int: %d bytes\n", sizeof(int));
    printf("Tamanho na memoria do tipo de dado char: %d bytes\n", sizeof(char));
    printf("Tamanho na memoria do tipo de dado float: %d bytes\n", sizeof x);
    return 0;
}