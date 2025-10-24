#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
/*  Faça um algoritmo que recebe duas matrizes nxn armazenadas 
nos vetores v1 e v2 e, calcula uma nova matriz a ser armazenada 
no vetor v3 que corresponde a multiplicação da transposta da 
matriz armazenada no vetor v1 pela matriz armazenada no vetor 
v2. Considere que o vetor v3 já está devidamente alocado. Não 
pode usar matrizes ou vetores auxiliares. 
Obs: não é para tentar transpor a matriz armazenada no vetor v1.  
int MultiplicaMatrizes (int *v1, int *v2, int *v3, int n) */

int MultiplicaMatrizes(int *v1, int *v2, int *v3, int n) {
    int i, j, k;
    if (v1 != NULL && v2 != NULL && n > 0) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                v3[i * n + j] = 0;
                for (k = 0; k < n; k++) {
                    v3[i * n + j] += v1[k * n + i] * v2[k * n + j];
                //  v3[i][j]  +=     v1[k][i] * v2[k][j]
                //  como v1 normal é v1[i][k] então para acessar os elementos de sua transposta é v1[k][i] == v1[k * n + i]
                }
            }
        }
        return TRUE;
    }   
    return FALSE;
}



int main() {
    int vet1[] = {5, 7, 8, 
                2, 11, 4, 
                3, 6, 1};
    int vet2[] = {8, 2, 4,
                6, 3, 9,
                11, 1, 7};
    int *vet3;
    vet3 = (int *) malloc (sizeof(int) * 3 * 3);

    MultiplicaMatrizes(vet1, vet2, vet3, 3);
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", vet3[i * 3 + j]);
        }
        printf("\n");
    }


    return 0;
}