#include <stdlib.h>

int **transposta(int **ma, int n, int m) {
    int **matrans;
    int i, j;

    if (ma != NULL && n > 0 && m > 0) {
        matrans = (int**) malloc(sizeof(int*) * m);
        // algumacoisa = (int **) malloc(sizeof(int*) * m);
        if (matrans != NULL) {
            for (i = 0; i < m; i++) {
                matrans[i] = (int*) malloc(sizeof(int) * n);
                
                if (matrans[i] == NULL) {
                    for (int k = 0; k < i; k++) {
                        free(matrans[k]);
                    }
                    free(matrans);
                    return NULL;
                }
            }

            //transposta
            for (i = 0; i < n; i++) {
                for (j = 0; j < m; j++) {
                    matrans[j][i] = ma[i][j];
                }
            }

            return matrans;
        }
    }
    return NULL;
}