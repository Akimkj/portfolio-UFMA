#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/*
Escreva um algoritmo que recebe uma matriz de numeros inteiros, com n linhas e m colunas, armazenadas no vetor v, e usa o TAD Stack para inverter os primeiros m elementos da linha l da matriz.
int InverteOrdemElementosLinhaK(int *v, int n, int l);
*/

int InverteOrdemElementosLinhaK(int *v, int m, int l) {
    Stack *stktemp;
    if (v != NULL) {
        stktemp = stkCreate(m);
        if (stktemp != NULL) {
            if (l >= 0 && l < m) {
                for (int i = 0; i < m; i++) {
                    push(stktemp, (void*) v[l * m + i]);
                }
                for (int j = 0; j < m; j++) {
                    v[l * m + j] = (int) pop(stktemp);
                }
                stkDestroy(stktemp);
                return TRUE;
            }
            stkDestroy(stktemp);
        }
    }
    return FALSE;
}

int main() {
    int vet[] = {
        1, 2, 3,
        4, 5, 6,
        7, 8, 9
    };

    int *ptrVet;
    ptrVet = vet;

    InverteOrdemElementosLinhaK(ptrVet, 3, 0);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", vet[i * 3 + j]);
        }
        printf("\n");
    }

    return 0;
}