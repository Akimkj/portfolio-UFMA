#include <stdio.h>
#include <stdlib.h>
/*Aula 22 - operador long para o tipo double
    double -> %lf
    long double -> %Lf
    __mingw_printf()
*/
int main() {
    float x = 23.63347342357;
    printf("o valor de x: %f\n", x);
    printf("tamanho de x: %d bytes\n\n", sizeof x);

    double y = 5.73467247473;
    printf("O valor de y: %lf\n", y);
    printf("O tamanho de y: %d bytes\n\n", sizeof y);

    //Ao utilizar o operador long numa variável do tipo double, a quantidade de armazenamento necessária para aquele dado altera dependendo do compilador e da arquitetura do computador. Por exemplo, existem pc's que reservam 16 bytes ou 12 bytes para esse tipo de dado.
    long double z = 3.5035298628368;
    //Para imprimir um dado long double, no MAC ou no linux, é apenas necessário usar o especificador %Lf, no entanto, já que o long double tem mais doq 64 bits, o windows não suporta
    printf("O valor de z: %Lf\n", z);
    // Já que o windows não suporta a impressão do tipo long double, usamos uma função do próprio compilador para imprimir esse valor.
    __mingw_printf("O valor de z: %Lf\n", z);
    printf("O tamanho de z: %d bytes\n\n", sizeof z);

    return 0;
}