#include <stdio.h>
#include <stdlib.h>
/*Aula 17 - operador short para o tipo

sizeof x ou sizeof (int)
*/
int main() {
    short int x = 32767;
    printf("\nTamanho padrao do tipo int: %d bytes\n", x);
    x++;
    printf("Tamanho da variavel do tipo int com operador short: %d bytes\n", x);
    return 0;
}
