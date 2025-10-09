#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int TrocaElmsVetor(int *v, int n, int p, int q) {
    if (v == NULL || n <= 0 || p < 0 || q < 0 || p >= n || q >= n) {
        return FALSE;
    } 

    int aux;
    aux = v[p];
    v[p] = v[q];
    v[q] = aux;

    return TRUE;
}


int UniaoVetores(int *a, int *b, int *c, int n) {
    if (a == NULL || b == NULL || c == NULL || n <= 0) {
        return FALSE;
    }
    int i = 0, j = 0, k = 0;
    int existe;

    for (int x = 0; x < n; x++) {
        c[k] = a[x];
        k++;
    }

    while (i < n) {
        existe = FALSE;
        j = 0;

        while (j < k && !existe) {
            if (b[i] == c[j]) {
                existe = TRUE;
            }
            j++;
        }

        if (!existe) {
            c[k] = b[i];
            k++;
        }
        i++;
    }
    

    return k;
}

int IntersecaoVetores(int *a, int *b, int *c, int n) { 
    if (a == NULL || b == NULL || c == NULL || n <= 0) {
        return FALSE;
    }
    int achouB, existeC, k = 0;

    for (int i = 0; i < n; i++) {
        achouB = FALSE;
        existeC = FALSE; 

        for (int j = 0; j < n; j++) {
            if (a[i] == b[j]) {
                achouB = TRUE;
            }
        }

        for (int m = 0; m < k; m++) {
            if (a[i] == c[m]) {
                existeC = TRUE;
            }
        }

        if (achouB && !existeC) {
            c[k] = a[i];
            k++;
        }
    }

    return k;
}

int ElemEmPosicaoImparNoVetor(int *a, int *b, int *c, int n) {
    if (a == NULL || b == NULL || c == NULL || n <= 0) {
        return FALSE;
    }

    int k = 0;

    for (int i = 1; i < n; i += 2) {
        c[k] = a[i];
        k++;
        c[k] = b[i];
        k++;
    }

    return k;
}


int main() {
    int v[] = {9, 3, 2, 8, 9};
    int tam = sizeof(v) / sizeof(int);

    printf("Vetor Antes: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }

    TrocaElmsVetor(v, tam, 0, 2);

    printf("\nVetor depois: ");
    for (int i = 0; i < tam; i++) {
        printf("%d ", v[i]);
    }


    int v1[] = {1, 2, 4, 3, 5, 10};
    int v2[] = {2, 2, 3, 1, 4, 42};
    int *v3 = (int*) malloc(6 * sizeof(int));
    int tamV3 = UniaoVetores(v1, v2, v3, 6);

    printf("\nUniao vetorC: ");
    for (int i = 0; i < tamV3; i++) {
        printf("%d ", v3[i]);
    }

    int *v4 = (int*) malloc(6 * sizeof(int));
    int tamV4 = IntersecaoVetores(v1, v2, v4, 6);
    printf("\nIntersecao vetorC: ");
    for (int i = 0; i < tamV4; i++) {
        printf("%d ", v4[i]);
    }
    

    int *v5 = (int*) malloc(6 * sizeof(int));
    int tamV5 = ElemEmPosicaoImparNoVetor(v1, v2, v5, 6);
    printf("\nElmPosicao Impar vetorC: ");
    for (int i = 0; i < tamV5; i++) {
        printf("%d ", v5[i]);
    }
    return 0;
 }