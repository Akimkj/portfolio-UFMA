#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAT_QUAD 0
#define MAT_SIMET 1
#define MAT_DIAG 2
#define MAT_ANTISIMET 3
#define MAT_NORMAL -1

//QUESTÃO A
int tipodeMatriz(int *va, int n, int m) {
    if(n == m) {
        int haElemDiferente = FALSE, ehDiagonal = TRUE, ehAntiSimet = TRUE;
        int itemAtual, transpostaItem;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                itemAtual = va[i * m + j];
                transpostaItem = va[j * m + i];

                if (itemAtual != transpostaItem && haElemDiferente == FALSE) {
                    haElemDiferente = TRUE;
                }
                if ((i != j) && (itemAtual != 0) && (ehDiagonal == TRUE)) {
                    ehDiagonal = FALSE;
                }
                if (itemAtual + transpostaItem != 0) {
                    ehAntiSimet = FALSE;
                }
            }
        }

        if (ehDiagonal) {
            return MAT_DIAG;
        }
        if (!haElemDiferente) {
            return MAT_SIMET;
        }
        if(ehAntiSimet) {
            return MAT_ANTISIMET;
        }
        return MAT_QUAD;
    }
    return MAT_NORMAL;
}

//QUESTÃO B
int *transposta(int *va, int n, int m) {
    if (va != NULL && n > 0 && m > 0) {
        int *transposta;
        transposta = (int*) malloc(sizeof(int) * n * m);
        if (transposta == NULL) {
            free(transposta);
            return NULL;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                transposta[i * n + j] = va[j * m + i];
            }
        }

        return transposta;
    }
    return NULL;
}

//QUESTÃO C
int *multiplicapelaTransposta(int *va, int n, int m) {
    if (va != NULL && n > 0 && m > 0) {
        int *result;
        result = (int*) malloc(sizeof(int) * n * n);
        if (result == NULL) {
            return NULL;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                result[i * n + j] = 0;
                for (int k = 0; k < m; k++) {
                    result[i * n + j] += va[i * m + k] * va[j * m + k];
                }
            }
        }

        return result;
    }   
    return NULL;
}


//QUESTÃO D
int * linhadaMatriz(int *va, int n, int m, int l) {
    if (va != NULL && n > 0 && m > 0) {
        if (l < m && l >= 0) {
            int *matLinha;
            matLinha = (int*) malloc(sizeof(int) * m);

            for (int i = 0; i < m; i++) {
                matLinha[i] = va[l * m + i];
            }

            return matLinha;
        }
    }
    return NULL;
}  

//QUESTÃO E
int *colunadaMatriz(int *va, int n, int m, int p) {
    if (va != NULL && n > 0 && m > 0) {
        if (p < n && p >= 0) {
            int *matColuna;
            matColuna = (int*) malloc(sizeof(int) * n);
            if (matColuna != NULL) {
                for (int j = 0; j < n; j++) {
                    matColuna[j] = va[j * m + p];
                }

                return matColuna;
            }
            free(matColuna); 
        }
    }
    return NULL;
}

//QUESTÃO F
int *diagonaldaMatriz(int *va, int n, int m) {
    if (n == m && va != NULL && n > 0 && m > 0) {
        int *vetDiag;
        vetDiag = (int*) malloc(sizeof(int) * n);
        if (vetDiag != NULL) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (i == j) {
                        vetDiag[i] = va[i * m + j];
                    }
                }
            }
            return vetDiag;
        }
        free(vetDiag);
    }
    return NULL;
}



int main() {
    int mat[] = {1, 1, 0,
                1, 8, 0,
                0, 0, 9};

    printf("tipo matriz: %d\n", tipodeMatriz(mat, 3, 3));

    int mat1[] = {1, 4, 
                2, 4, 
                5, 6};
    int *transMat;
    transMat = transposta(mat1, 3, 2);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", transMat[i * 3 + j]);
        }
        printf("\n");
    }
    printf("\n\n");
    int *multip;
    multip = multiplicapelaTransposta(mat1, 3, 2);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", multip[i * 3 + j]);
        }
        printf("\n");
    }

    printf("\n\n\n");

    int *linhaTeste;
    linhaTeste = linhadaMatriz(mat, 3, 3, 0);
    for (int j = 0; j < 3; j++) {
            printf("%d ", linhaTeste[j]);
    }

    printf("\n\n\n");

    int *colunaTeste;
    colunaTeste = colunadaMatriz(mat, 3, 3, 2);
    for (int j = 0; j < 3; j++) {
            printf("%d\n", colunaTeste[j]);
    }

    printf("\n\n\n");

    int *DIAGTeste;
    DIAGTeste = diagonaldaMatriz(mat, 3, 3);
    for (int i = 0; i < 3; i++) {
            printf("%d ", DIAGTeste[i]);
    }

    return 0;
}