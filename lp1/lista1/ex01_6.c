#include <stdio.h>
/*a funcão printf(), além de imprimir o que é colocado, ainda retorna um inteiro com a quantidade de caracteres impressos*/
int main() {
    if (printf("0")) {
        printf("dentro do if");
    }
    else {
        printf("dentro do else");
    }
}