#include <stdio.h>

typedef struct {
    int idade;
    char nome[50];
}Pessoa;

int main() {

    Pessoa familia[5];

    for (int i = 0; i < 5; i++) {
        printf("Escreva o nome do membro %d da familia: ", i + 1);
        fgets(familia[i].nome, sizeof(familia[i].nome), stdin);
        
        printf("Escreva a idade do membro %d da familia: ", i + 1);
        scanf("%d", &familia[i].idade);
        getchar();
    }

    for (int i = 0; i < 5; i++) {
        printf("Nome: %s, idade: %d\n", familia[i].nome, familia[i].idade);
    }
    return 0;
}