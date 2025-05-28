#include <stdio.h>
/*função recursiva que imprimir todos os valores de n até 0*/
void imprimir(int num) {
    if (num == 0) {
        printf("%d\n", num);
    }
    else {
        imprimir(num - 1);
        printf("%d\n", num);
    }
}

int main() {
    imprimir(5);
    return 0;
}