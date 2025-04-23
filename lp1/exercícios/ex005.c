#include <stdio.h>
#include <math.h>
int main() {
    float num, raiz;
    printf("Digite um numero: ");
    scanf("%f", &num);
    raiz = sqrt(num);

    if (raiz == (int)raiz) {
        printf("quadrado perfeito");
    }
    else {
        printf("nao e");
    }
    return 0;
}