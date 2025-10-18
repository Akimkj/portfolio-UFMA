#include <stdio.h>
#include <stdlib.h>
/*Aula 7 - lendo caracteres com getchar()*/
int main() {
    char sexo;
    printf("Digite seu sexo: ");
    sexo = getchar();

    printf("Seu sexo: %c", sexo);
    
    return 0;
}