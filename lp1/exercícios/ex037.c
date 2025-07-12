#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char id;
    float custo;
    float retorno;
}Acao;
float pegarCapitalDisponivel(char f[]);
void preencherAcoes(Acao actions[]);


int main() {
    char nomeArquivo[] = {"iniciante.txt"};
    float capital_disponivel = pegarCapitalDisponivel(nomeArquivo);
    Acao acoes[4];
    preencherAcoes(acoes);
    for (int i = 0; i < 4; i++)
        printf("ID: %c\tCusto: %.2f\tRetorno: %.2f\t\n", acoes[i].id, acoes[i].custo, acoes[i].retorno);
    
    return 0;
}

void preencherAcoes(Acao actions[]) {
    FILE *file = fopen("iniciante.txt", "r");
    char linha[500];
    int num_acoes = 0;

    while (fgets(linha, sizeof(linha), file) != NULL) {
    // Ignorar linhas em branco ou de comentários
    if (linha[0] == '#' || strlen(linha) <= 1) {
        continue;
    }

    // Tentar ler os dados de uma ação
    if (fscanf(file, "%c %f %f", &actions[num_acoes].id, &actions[num_acoes].custo, &actions[num_acoes].retorno) == 3) {
        num_acoes++;
    }
}
}
float pegarCapitalDisponivel(char f[]) {
    FILE *file = fopen(f, "r");
    float cap_init = 0;
    if (file) {
        char linha[500];
        while (fgets(linha, sizeof(linha), file))
        {
        sscanf(linha, "CAPITAL_DISPONIVEL_R$: %f", &cap_init);
        }
    }
    else {
        printf("erro!");
    }
    fclose(file);
    free(file);
    return cap_init;
    
}
