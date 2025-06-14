#include <stdio.h>

void imprimir(int vet[], int* tam) {
    for (int i = 0; i < *tam; i++) {
        printf("%d ", *(vet + i));
    }
}

int main() {
    int vet[] = {5, 6, 8, 1, 72, 62};
    int tamanho = sizeof(vet)/sizeof(vet[0]);
    imprimir(vet, &tamanho);
}