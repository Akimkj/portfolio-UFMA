#include <stdio.h>
#include <stdlib.h>

int **transposta(int **ma, int n, int m, int **matrans) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrans[j][i] = ma[i][j];
        }
    }
    return matrans;
}

int main() {
    int linha = 2, coluna = 3;
    int **mat;

    mat = (int**) malloc(linha * sizeof(int *));
    for (int i = 0; i < linha; i++) {
        mat[i] = (int*) malloc(coluna * sizeof(int));
    }

    int valores[2][3] = {
        {4, 5, 2}, 
        {7, 9, 1}
    };

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            mat[i][j] = valores[i][j];
        }
    }

    int **matrans;
    matrans = (int**) malloc (coluna * sizeof(int*));
    for (int a = 0; a < coluna; a++) {
        matrans[a] = (int*) malloc(linha * sizeof(int));
    }

    int **resultado = transposta(mat, linha, coluna, matrans);

    printf("matriz transposta:\n");
    for (int i = 0; i < coluna; i++) {
        for(int j = 0; j < linha; j++) {
            printf("%d ", resultado[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < linha; i++) { free(mat[i]); }
    free(mat);
    return 0;
}