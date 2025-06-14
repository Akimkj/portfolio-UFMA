#include <stdio.h>

void encontrar_Maior_Menor(int vet[], int tam, int* menor, int* maior) {
    *menor = *vet;
    *maior = *vet;
    for(int i = 0; i < tam; i++) {
        if (*(vet + i) > *maior) {
            *maior = *(vet + i);
        }
        if (*(vet + i) < *menor) {
            *menor = *(vet + i);
        }
    }
}

int main() {
    int vet[] = {6, 73, 1,6 , -6, 1, 9};
    int tamanho = sizeof(vet)/sizeof(vet[0]);
    int maior, menor;
    encontrar_Maior_Menor(vet,tamanho, &menor, &maior);
    printf("Menor: %d\nMaior: %d\n", menor, maior);
    return 0;
}