#include <stdio.h>

void mostrarInverso(int vet[], int tam) {
    for (int i = tam - 1; i >= 0; i--) {
        printf("%d ", vet[i]);
    }
}

int main() {
    int vetor[] = {3, 7, 4, 1, 6, 2, 3, 9};
    int tamanho = sizeof(vetor)/sizeof(int);
    for (int j = 0; j < tamanho; j++) {
        printf("%d ", vetor[j]);
    }
    printf("\n");
    mostrarInverso(vetor, tamanho);
    return 0;
}