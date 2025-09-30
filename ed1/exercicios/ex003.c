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


int UniaoVetores(int *a, int *b, int *c, int n, int m) {
    if (a == NULL || b == NULL || c == NULL || n <= 0 || m <= 0) {
        return FALSE;
    }
    int i = 0, j = 0, k = 0;
    int existe;

    for (int x = 0; x < n; x++) {
        c[k] = a[x];
        k++;
    }

    while (i < m) {
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

int IntersecaoVetores(int *a, int *b, int *c, int n, int m) {
    if (a == NULL || b == NULL || c == NULL || n <= 0 || m <= 0) {
        return FALSE;
    }

    for(int i = 0; i < n;)
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


    int v1[] = {1, 4, 6, 2};
    int v2[] = {2, 7, 3, 1, 8};
    int *v3 = (int*) malloc(5 * sizeof(int));
    int tamV3 = UniaoVetores(v1, v2, v3, 4, 5);

    printf("\nUniao vetorC: ");
    for (int i = 0; i < tamV3; i++) {
        printf("%d ", v3[i]);
    }


    printf("Interseccao vetorC: ");
    for (int i =)

    return 0;
}