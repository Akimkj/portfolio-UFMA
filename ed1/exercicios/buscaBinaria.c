#include <stdio.h>
int buscaBinaria(int vet[], int tam, int chave) {
    int left = 0, right = tam - 1;

    while( left <= right) {
        int meio = (left + right) / 2;
        if(vet[meio] == chave) {
            return 1;
        }
        else if (vet[meio] > chave) {
            right = meio - 1;
        }
        else {
            left = meio + 1;
        }
    }
    return 0;


}


int main() {
    int vet[] = {3, 5, 6, 10, 46, 56, 63, 76, 80, 90, 100};
    int chave = 100;
    int tam = sizeof(vet)/sizeof(int);
    // busca binária
    if (buscaBinaria(vet, tam, chave)) {
        printf("Esta!");
    }
    else {
        printf("Nao");
    }
    return 0;
}