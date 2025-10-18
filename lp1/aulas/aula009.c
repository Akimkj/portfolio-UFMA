#include <stdio.h>
#include <stdlib.h>
/*Aula 9 - lendo caracteres com fgetc()*/
int main() {
    char caracter;
    printf("Digite seu caracter: ");
    caracter = fgetc(stdin);

    printf("Seu caracter: %c", caracter);
    
    return 0;
}