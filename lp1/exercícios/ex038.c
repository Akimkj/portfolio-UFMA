#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
w - write
r - read
a - anexar
r+ -> ler e escrever
w+ -> ler e escrever (se o arquivo existir, ele apaga o conteudo existente)
*/

typedef struct {
    char id;
    float custo;
    float retorno;
}Acao;



float pegarCapitalDisponivel(char f[]) {
    FILE *arquivo;
    arquivo = fopen(f, "r");
    float cap_disponivel = 0;
    if(arquivo) {
        char linha[500];
        while (fgets(linha, sizeof(linha), arquivo)) {
            printf("%d\n", sscanf(linha, "CAPITAL_DISPONIVEL_R$: %f", &cap_disponivel));
        }
        
    }
    else {
        printf("Erro ao abrir o arquivo!");
    }
    fclose(arquivo);
    free(arquivo);
    return cap_disponivel;
}


void preencherAcoes(Acao actions[]) {
    FILE *arquivo = fopen("iniciante.txt", "r");
    char linha[500];
    int num_acoes = 0;

    while (fgets(linha, sizeof(linha), arquivo)) {
        // Ignorar linhas em branco ou de comentários
        if (linha[0] == '#' || strlen(linha) <= 1) {
            continue;
        }

        // Tentar ler os dados de uma ação
        if (sscanf(linha, "%c %f %f", &actions[num_acoes].id, &actions[num_acoes].custo, &actions[num_acoes].retorno) == 3) {
            num_acoes++;
        }
    }

    fclose(arquivo);
    free(arquivo);
}


int main() {
    char nomeArquivo[] = {"iniciante.txt"};
    float capitalDisponivel = pegarCapitalDisponivel(nomeArquivo);
    Acao vetorAcoes[4];
    preencherAcoes(vetorAcoes);

    /*for (int i = 0; i < 4; i++) {
        printf("ID: %c\tCusto: %.2f\tRetorno: %.2f\n", vetorAcoes[i].id, vetorAcoes[i].custo, vetorAcoes[i].retorno);
    }*/

    return 0;
}