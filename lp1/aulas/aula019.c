#include <stdio.h>
#include <stdlib.h>
/*Aula 19 - uso do operador long
%li / %lld
*/

int main() {
    //Tudo depende da arquitura do computador do usuário. Antigamente, nas arquiteturas mais antigas de computador, o tipo int ocupava apenas 2 bytes de memória, e o operador long serve para aumentar o tamanho do tipo int para 4 bytes. No entanto, com a evolução da arquitetura desses computadores, o tipo int, por padrão, começou a ocupar 4 bytes de memória, logo: int == long int. Então para aumentar a quantidade de memória do tipo int, é necessário usar 2 long.
    long long int num = 2147483647;
    printf("Tamanho da variavel: %d bytes\n", sizeof num);
    // para imprimir um dado long long int, usamos o especificador %lld
    printf("Agora o valor e %lld \n", num);
    num++;
    printf("Agora o valor e %lld \n", num);
    return 0;
}