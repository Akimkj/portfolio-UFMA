#include <stdlib.h>
#include <stdio.h>

int main() {
    int m = 3, n = 3;
    double **A, *x, *Ax, *B;
    A = (double **) malloc(m * sizeof(double*));
    if (A == NULL) {
        return -1;
    }
    for (int i = 0; i < m; i++) {
        A[i] = (double *) malloc(n * sizeof(double));
        if (A[i] == NULL) {
            return -1;
        }
    }

    Ax = (double *) malloc (m * sizeof(double));
    B = (double *) malloc (m * sizeof(double));
    x = (double *) malloc (n * sizeof(double));

    // Leitura da matriz A
    printf("Digite os elementos da matriz A (%d x %d):\n", m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }
    
    // Leitura do vetor x
    printf("Digite os elementos do vetor x (%d elementos):\n", n);
    for (int j = 0; j < n; j++) {
        scanf("%lf", &x[j]);
    }
    
    // Leitura do vetor B
    printf("Digite os elementos do vetor B (%d elementos):\n", m);
    for (int i = 0; i < m; i++) {
        scanf("%lf", &B[i]);
    }
    
    // Cálculo do produto Ax
    for (int i = 0; i < m; i++) {
        Ax[i] = 0.0;
        for (int j = 0; j < n; j++) {
            Ax[i] += A[i][j] * x[j];
        }
    }

    for (int i = 0; i < m; i++) {
        if (Ax[i] - B[i] > 0.000001) {
            printf("Não\n");
            return 0;
        }
    }

    printf("SIM\n");
    // Liberação da memória alocada
    for (int i = 0; i < m; i++) {
        free(A[i]);
    }
    free(A);
    free(x);
    free(B);
    free(Ax);
    
    return 0;
}