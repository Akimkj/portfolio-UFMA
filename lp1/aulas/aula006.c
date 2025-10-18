#include <stdio.h>
#include <stdlib.h>
/*Aula 6 - Criando variáveis e lendo caracteres*/
// OBS: toda tecla do teclado é um caracter
int main() {
    char sexo;
    printf("Digite seu sexo: ");
    scanf("%c", &sexo);

    printf("Seu sexo: %c", sexo);
    
    return 0;
}