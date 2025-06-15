#include <stdio.h>
#include <stdlib.h>

int main() {
    int *vet, tam;
    printf("Quantas lotes terão de mercadoria? ");
    scanf("%d", &tam);
    vet = malloc(tam * sizeof(int));
    if (vet == NULL) {
        printf("Falha na alocacao\n");
    }
    else {
        printf("Alocacao bem sucedida!\n");
    }

    printf("Preencha os espaços:\n");
    for (int i = 0; i < tam; i++) {
        printf("Elemento %d: ", i+1);
        scanf("%d", vet + i);
    }

    for (int i = 0; i < tam; i++)
    {
        printf("%d ", *(vet+i));
    }
    
    return 0;
}