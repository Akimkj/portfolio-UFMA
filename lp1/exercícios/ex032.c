#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int tam, *v;
    scanf("%d", &tam);

    v = malloc(tam * sizeof(int));
    if (v == NULL) {
        printf("Alocação falhou!\n");
        return -1;
    }

    for (int i = 0; i < tam; i++) {
        *(v + i) = rand() % 1000;
    }
    for (int a = 0; a < tam; a++)
    {
        printf("%d ", *(v + a));
    }

    printf("\nDigite o novo tamanho do vetor: ");
    scanf("%d", &tam);

    v = realloc(v, tam * sizeof(int));

    for (int a = 0; a < 5; a++)
    {
        printf("%d ", *(v + a));
    }

    free(v);
    return 0;
    

}