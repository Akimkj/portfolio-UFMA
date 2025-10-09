#include <stdio.h>
#include <stdlib.h>
/*Em todas as assinaturas das letras dessa questão, foi necessário alterar a assinatura da função, em específico o VA[][] para **VA */


int *DevolveVetorLinhaI (int **VA, int N, int M,  int I, int vetor[]) {
    if (I >= N || I < 0) {
        return NULL;
    }

    for(int k = 0; k < M; k++) {
        vetor[k] = VA[I][k];
    }

    return vetor;
}

int *DevolverVetorColunaJ(int **VA, int N, int M, int J, int vetor[]) {
    if (J >= M || J < 0) {
        return NULL;
    }

    for (int i = 0; i < N; i++) {
        vetor[i] = VA[i][J];
    }

    return vetor;
}

int *DevolverVetorDiagonal (int **VA, int N, int M, int vetor[]) {
    if (N != M) {
        return NULL;
    }

    int i = 0, j = 0;

    while (i < N) {
        vetor[i] = VA[i][j];
        i++;
        j++;
    }

    return vetor;
}

int main() {
    int linha = 3, coluna = 3;
    int **mat;

    mat = (int**) malloc(linha * sizeof(int *));
    for (int i = 0; i < linha; i++) {
        mat[i] = (int*) malloc(coluna * sizeof(int));
    }

    int valores[3][3] = {
        {4, 5, 2}, 
        {7, 9, 1}, 
        {10, 9, 7}
    };

    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            mat[i][j] = valores[i][j];
        }
    }

    int vet1[linha];
    int vet2[coluna];
    int vet3[linha];
    int *resultado1 = DevolveVetorLinhaI(mat, linha, coluna, 2, vet1);
    int *resultado2 = DevolverVetorColunaJ(mat, linha, coluna, 1, vet2);
    int *resultado3 = DevolverVetorDiagonal(mat, linha, coluna, vet3);

    
    printf("Linha l escolhida: ");
    for (int i = 0; i < linha; i++) {
        printf("%d ", resultado1[i]);
    }

    printf("\nColuna J escolhida: ");
    for(int j = 0; j < linha; j++) {
        printf("%d ", resultado2[j]);
    }

    printf("\nDiagonal principal: ");
    for (int k = 0; k < linha; k++) {
        printf("%d ", resultado3[k]);
    }

    
    for (int i = 0; i < linha; i++) { free(mat[i]); }
    free(mat); 
    return 0;
}