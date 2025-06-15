#include <stdio.h>
void imprimir_vetor(int vet[], int *tam) {
    for (int i = 0; i < *tam; i++) {
        printf("%d ", *(vet + i));
    }
    printf("\n\n");
}
void bubble_sort(int vet[], int *tam) {
    int temp;
    for (int i = 0; i < *tam - 1; i++) {
        for (int j = 0; j < *tam - 1; j++) {
            if (*(vet + j) > *(vet + j + 1)) {
                temp = *(vet + j);
                *(vet + j) = *(vet + j + 1);
                *(vet + j + 1) = temp;
            }
        }
    }
}

int main() {
    int vet[] = {5, 72, 1, 67, 56, 0, -5, 12, 62, 73, 71, 9, 2};
    int tamanhoVet = sizeof(vet)/sizeof(vet[0]);
    imprimir_vetor(vet, &tamanhoVet);
    bubble_sort(vet, &tamanhoVet);
    imprimir_vetor(vet, &tamanhoVet);
    return 0;
}