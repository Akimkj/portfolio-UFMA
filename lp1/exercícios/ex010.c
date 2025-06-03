#include <stdio.h>

void mostrarVetor(int *vnotas) {
    for (int i = 0; i < 5; i++) {
        printf("%d ", vnotas[i]);
    }
}
int main() {
    int notas[5];
    for (int j = 0; j < 5; j++) {
        printf("Digite o %d inteiro: ", j + 1);
        scanf("%d", &notas[j]);
    }
    mostrarVetor(notas);
    printf("\n\n\n");
    for (int k = 0; k < 5; k++) {
        notas[k] *= 3;
    }

    mostrarVetor(notas);
    return 0;
}