#include <stdio.h>
#include <stdlib.h>
// j j1
// 2 3 4 5 1
void rotacionarVetor(int* vetor, int tam, int rotacoes) {
    
    for (int i = rotacoes; i > 0; i--) {
        for (int j = 0; j < tam - 1; j++) {
            int temp = vetor[j+1];
            vetor[j+1] = vetor[j]; 
            vetor[j] = temp;
        }
    }

}
int main() {
    int tamanho = 5;
    int *vet = malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        vet[i] = i +1;
    }
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    printf("\n");
    rotacionarVetor(vet, tamanho, 3);

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vet[i]);
    }
    return 0;
}