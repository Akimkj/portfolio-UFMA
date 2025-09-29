#include <stdio.h>

#define TRUE 1
#define FALSE 0

int TrocaElmsVetor(int *v, int n, int p, int q) {
    if (v == NULL || n <= 0 || p < 0 || q < 0) {
        return FALSE;
    }

    int aux;
    aux = v[p];
    v[p] = v[q];
    v[q] = aux;

    return TRUE;
}

int main() {
    int v[] = {9, 3, 2, 8, 9};
    int tam = sizeof(v) / sizeof(int);

    printf("Vetor Antes: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }

    int value = TrocaElmsVetor(v, tam, 0, 2);
    if (value) {
        printf("\nTroca efetuada!");
    }
    else {
        printf("\nTroca não efetuada!");
        
    }

    
    printf("\nVetor depois: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }

    return 0;
}