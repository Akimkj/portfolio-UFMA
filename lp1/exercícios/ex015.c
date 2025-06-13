#include <stdio.h>
void ordenarVetor(int vetor[], int tam) {
    for (int i = 0; i < tam -1 ; i++) {
        for (int j = 0; j < tam - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;
            }
        }
    } 
    for (int a = 0; a < tam; a++)
        printf("%d ", vetor[a]);
}
//             i    j
// {-7, 0, 1, 123, 85, 74, 65, 64, 32}

int main() {
    int vet[] = {63, 85, 32, 123, 74, 1, 65, 0, -7};
    int tamanho = sizeof(vet)/sizeof(int);
    for (int a = 0; a < tamanho; a++)
        printf("%d ", vet[a]);
    printf("\n");
    ordenarVetor(vet, tamanho);
    return 0;
}