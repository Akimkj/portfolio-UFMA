#include <stdio.h>

int main() {
    int max = 4, ac = 0, menor = 10;
    int notas[max];

    int i;
    for(i = 0; i < max; i++) {
        printf("Digite a nota %d: ", i+1);
        scanf("%d", &notas[i]);

        while(notas[i] > 10 || notas[i] < 0) {
            printf("Digite uma nota entre 0 e 10: ");
            scanf("%d", &notas[i]);
        }
        if (menor > notas[i]) {
            menor = notas[i];
        }

        ac += notas[i];
    }

    if (ac == 0) {
        return -1;
    }
    int media = ac / max;
    int notaNec = 0;
    if (media < 7) {
        notaNec = 12 - media;
    }

    printf("\nMedia: %d", media);
    printf("\nMenor nota: %d", menor);
    printf("\nNota necessaria para recuperar: %d", notaNec);

    return 0;
}

/*ANOTAÇÃO: na opção de montagem x86-64 gcc 4.1.2, que será usada no Compiler Explorer, a organização do for não aceita declaração de variável dentro dos parênteses*/