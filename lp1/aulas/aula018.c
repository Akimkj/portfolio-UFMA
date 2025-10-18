#include <stdio.h>
#include <stdlib.h>
/*Aula 18 - tamanho de um int na memória
intervalo: -2.147.483.648 até 2.147.483.647

*/

int main() {
    // O comportamento desse código ocorre devido ao fato de que o tipo int armazena 4 bytes (32 bits), e qualquer número decimal que ultrapasse essa quantidade de bits para armazena-la, ocorre o estouro de memória. 
    int num = 2147483647;
    printf("Agora o valor e %d\n", num);
    num++;
    printf("Agora o valor e %d\n", num);
    return 0;
}