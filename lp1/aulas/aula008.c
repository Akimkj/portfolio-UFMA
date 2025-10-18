#include <stdio.h>
#include <stdlib.h>
/*Aula 8 - lendo caracteres com getc()*/
int main() {
    char caracter;
    printf("Digite seu caracter: ");
    caracter = getc(stdin);

    printf("Seu sexo: %c", caracter);
    
    return 0;
}