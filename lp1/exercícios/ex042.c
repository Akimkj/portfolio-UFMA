#include <stdio.h>
#include <stdlib.h>

int *func(int *nums, int n, int alvo) {
    int *r = (int*) malloc(2 *sizeof(int));
    if (r == NULL) {
        return NULL;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(nums + i) + *(nums + j) == alvo) {
                r[0] = i;
                r[1] = j;
                return r;
            }
        }
    }
    return NULL;
}

int main() {
    int tam = 5;
    int *vet = (int *) malloc(tam * sizeof(int));
    if (vet == NULL) {
        return -1;
    }

    for (int i = 0; i < tam; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &vet[i]);
    }

    int *index = func(vet, tam, 5);

    for (int i = 0; i < 2; i++) {
        printf("%d ", index[i]);
    }

    free(vet);
    free(index);
    return 0;
}