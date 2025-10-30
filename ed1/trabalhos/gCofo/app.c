#include <stdio.h>
#include <stdlib.h>
#include "gCofo.h"

void menuOpcoes() {
    printf("\n");
    printf("\t1. Criar uma nova colecao\n");
    printf("\t2. adicionar elemento\n");
    printf("\t3. remover elemento\n");
    printf("\t4. Consultar elemento\n");
    printf("\t5. Listar elementos\n");
    printf("\t6. Esvaziar colecao\n");
    printf("\t7. Destruir colecao\n");
    printf("\t8. Encerrar programa\n");
    printf("\nEscolha uma opcao: ");
}


int main() {
    int flagParada = TRUE;
    int opcao, result;
    Gcofo *jogos = NULL;
    Jogo *jogo, *aux;

    while (flagParada == TRUE) {
        menuOpcoes();
        scanf("%d", &opcao);
        while (opcao < 1 || opcao > 8) {
            printf("\nEscolha uma das opcoes possiveis:");
            menuOpcoes();
            scanf("%d", &opcao);
        }
        if (opcao == 1) {
            int tamMax;
            if (jogos != NULL) {
                printf("\n>>>>>>>>>>Uma colecao ja esta criada<<<<<<<<<<\n");
            }
            else {
                printf("Digite o tamanho maximo da colecao: ");
                scanf("%d", &tamMax);
                jogos = GcofoCreate(tamMax);
                if (jogos != NULL) {
                    printf("\n>>>>>>>>>>COLECAO CRIADA!<<<<<<<<<<\n");
                }
                else {
                    printf("\n>>>>>>>>>>Falha ao criar colecao!<<<<<<<<<<\n");
                }
            }
        }
        else if (opcao == 2) {
            if (jogos == NULL) {
                printf("\n>>>>>>>>>>Primeiramente, crie uma colecao<<<<<<<<<<\n");
            }
            else {
                jogo = (Jogo*) malloc (sizeof(Jogo));
                if (jogo != NULL) {
                    getchar();
                    printf("Digite o nome do jogo: ");
                    scanf("%100[^\n]", jogo->name);
                    printf("Digite o ano de lancamento do jogo: ");
                    scanf("%d", &(jogo->anoLancamento));
                    printf("Digite a nota do jogo: ");
                    scanf("%f", &(jogo->notaSteam));

                    
                    result = GcofoInsert(jogos, jogo);
                    if (result) {
                        printf("\n>>>>>>>>>>Jogo Inserido com Sucesso!<<<<<<<<<<\n");
                    }
                    else {
                        printf("\n>>>>>>>>>>Colecao ja esta cheia!!!<<<<<<<<<<\n");
                        free(jogo);
                    }
                }
                else {
                        printf("\n>>>>>>>>>>Falha ao inserir jogo na colecao<<<<<<<<<<\n");
                }
            }
        }
        else if (opcao == 3) { 
            if (jogos == NULL) {
                printf("\n>>>>>>>>>>Primeiramente, crie uma colecao<<<<<<<<<<\n");
            }
            else {
                char jogoRemover[100];
                Jogo *jogoRemovido;
                getchar();
                printf("Digite o nome do jogo que deseja remover: ");
                scanf("%100[^\n]", jogoRemover);

                jogoRemovido = GcofoRemove(jogos, jogoRemover);

                if (jogoRemovido != NULL) {
                    printf("\n>>>>>>>>>>Jogo removido com sucesso: <<<<<<<<<<");
                    printf("\n>>>>>>>>>>Nome: %s | Ano lancamento: %d | Nota: %.1f <<<<<<<<<<\n", jogoRemovido->name, jogoRemovido->anoLancamento, jogoRemovido->notaSteam);
                    free(jogoRemovido);
                }
                else {
                    printf("\n>>>>>>>>>>Não foi possivel localizar este jogo na colecao<<<<<<<<<<\n");
                }
            }
        }
        else if (opcao == 4) {
            if (jogos == NULL) {
                printf("\n>>>>>>>>>>Crie uma colecao primeiro<<<<<<<<<<\n");
            }
            else {
                char nomeProcurar[100];
                getchar();
                printf("Digite o nome do jogo que deseja achar: ");
                scanf("%100[^\n]", nomeProcurar);

                result = GcofoQuery(jogos, nomeProcurar);

                if (result == TRUE) {
                    printf("\n>>>>>>>>>>Elemento encontrado!<<<<<<<<<<\n");
                }
                else {
                    printf("\n>>>>>>>>>>Elemento nao esta presente na colecao!<<<<<<<<<<\n");
                }
            }
        }
        else if (opcao == 5) {
            if (jogos == NULL) {
                printf("\n>>>>>>>>>>Crie uma colecao primeiro<<<<<<<<<<\n");
            }
            else { //Tentar melhorar indentação do output
                printf("| %-28s | %-13s | %-8s |\n", "NOME", "ANO-LANCAMENTO", "NOTA");
                aux = GcofoGetFirst(jogos);
                if (aux != NULL) {
                    printf("| %-28s | %-13d | %-8.1f |\n", aux->name, aux->anoLancamento, aux->notaSteam);

                    for (int i = 1; i < GcofoGetSize(jogos); i++) {
                        aux = GcofoGetNext(jogos);
                        printf("| %-28s | %-13d | %-8.1f |\n", aux->name, aux->anoLancamento, aux->notaSteam);
                    }
                    printf("-------------------------------------------------------------------------------\n");
                }
                else {
                printf("A colecao esta vazia\n");
                }
            }
        }
        else if (opcao == 6) {
            if (jogos == NULL) {
                printf("\n>>>>>>>>>>Crie uma colecao primeiro<<<<<<<<<<\n");
            }
            else {
                result = GcofoEmpty(jogos);

                if (result == TRUE) {
                    printf("\n>>>>>>>>>>A colecao foi esvaziada<<<<<<<<<<\n");
                }
                else {
                    printf("\n>>>>>>>>>>Falha ao esvaziar a colecao!<<<<<<<<<<\n");
                }
            }
        }
        else if (opcao == 7) {
            if (jogos == NULL) {
                printf("\n>>>>>>>>>>Crie uma colecao primeiro<<<<<<<<<<\n");
            }
            else {
                result = GcofoDestroy(jogos);

                if (result == TRUE) {
                    printf("\n>>>>>>>>>>Colecao destruida com sucesso<<<<<<<<<<\n");
                    jogos = NULL;
                }
                else {
                    printf("\n>>>>>>>>>>A colecao precisa estar vazia<<<<<<<<<<\n");
                }
            }
        }
        else {
            flagParada = FALSE;
            printf("Encerrando programa...\n");
        }
    }

    if (jogos != NULL) {
        GcofoEmpty(jogos);
        GcofoDestroy(jogos);
    }

    return 0;
}