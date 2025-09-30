#include <stdio.h>
#define ERROR -1 

int MaiorElmVetor(int *v, int n) {
    if (v == NULL || n <= 0) {
        return ERROR;
    }

    int maior;
    maior = v[0];

    for (int i = 1; i < n; i++) {
        if (v[i] > maior) {
            maior = v[i];
        }
    }

    return maior;
}

int SomaElmsVetor(int *v, int n) { 
    if (v == NULL || n <= 0) {
        return ERROR;
    }

    int ac = 0;

    for (int i = 0; i < n; i++) {
        ac += v[i];
    }

    return ac;
}

int ElmDoMeioVetor(int *v, int n) {
    if (v == NULL || n <= 0) {
        return ERROR;
    }
    return v[n/2];
}

int main() {
    int v[] = {2, 7, 3, 5};
    int tam = sizeof(v)/sizeof(int);

    printf("Maior elemento: %d\n", MaiorElmVetor(v, tam));
    printf("Soma dos elementos: %d\n", SomaElmsVetor(v, tam));
    printf("Elemento do meio do vetor: %d\n", ElmDoMeioVetor(v, tam));
    return 0;
}