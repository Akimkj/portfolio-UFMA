#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sllist.h"

void menuOpcoes() {
    printf("\n");
    printf("\t1. Criar uma nova lista\n");
    printf("\t2. adicionar Jogos\n");
    printf("\t3. remover Jogos\n");
    printf("\t4. Consultar Jogos\n");
    printf("\t5. Listar Jogos\n");
    printf("\t6. Esvaziar lista\n");
    printf("\t7. Destruir lista\n");
    printf("\t8. Encerrar programa\n");
    printf("\nEscolha uma opcao: ");
}

int cmp(void *key, void *data) {
    
    char *nomeProcurado = (char *)key;
    Jogo *jogoNaLista = (Jogo *)data;

    if (strcmp(nomeProcurado, jogoNaLista->name) == 0) {
        return TRUE; 
    } else {
        return FALSE;
    }
}


int main() {
    int flagParada = TRUE;
    int opcao, result;
    SLList *jogos = NULL;
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
            if (jogos != NULL) {
                printf("\n>>>>>>>>>>Uma lista ja esta criada<<<<<<<<<<\n");
            }
            else {
                jogos = sllCreate();
                if (jogos != NULL) {
                    printf("\n>>>>>>>>>>LISTA CRIADA!<<<<<<<<<<\n");
                }
                else {
                    printf("\n>>>>>>>>>>Falha ao criar lista!<<<<<<<<<<\n");
                }
            }
        }
        else if (opcao == 2) {
            if (jogos == NULL) {
                printf("\n>>>>>>>>>>Primeiramente, crie uma lista<<<<<<<<<<\n");
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

                    
                    result = sllInsertAsLast(jogos, jogo);
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
                printf("\n>>>>>>>>>>Primeiramente, crie uma lista<<<<<<<<<<\n");
            }
            else {
                char jogoRemover[100];
                Jogo *jogoRemovido;
                getchar();
                printf("Digite o nome do jogo que deseja remover: ");
                scanf("%100[^\n]", jogoRemover);

                jogoRemovido = sllRemoveSpec(jogos, (void*) jogoRemover, cmp);

                if (jogoRemovido != NULL) {
                    printf("\n>>>>>>>>>>Jogo removido com sucesso: <<<<<<<<<<");
                    printf("\n>>>>>>>>>>Nome: %s | Ano lancamento: %d | Nota: %.1f <<<<<<<<<<\n", jogoRemovido->name, jogoRemovido->anoLancamento, jogoRemovido->notaSteam);
                    free(jogoRemovido);
                }
                else {
                    printf("\n>>>>>>>>>>Não foi possivel localizar este jogo na lista<<<<<<<<<<\n");
                }
            }
        }
        else if (opcao == 4) {
            if (jogos == NULL) {
                printf("\n>>>>>>>>>>Crie uma lista primeiro<<<<<<<<<<\n");
            }
            else {
                char nomeProcurar[100];
                getchar();
                printf("Digite o nome do jogo que deseja achar: ");
                scanf("%100[^\n]", nomeProcurar);

                result = sllQuery(jogos, nomeProcurar, cmp);

                if (result != FALSE) {
                    printf("\n>>>>>>>>>>Elemento encontrado!<<<<<<<<<<\n");
                }
                else {
                    printf("\n>>>>>>>>>>Elemento nao esta presente na lista!<<<<<<<<<<\n");
                }
            }
        }
        else if (opcao == 5) {
            if (jogos == NULL) {
                printf("\n>>>>>>>>>>Crie uma lista primeiro<<<<<<<<<<\n");
            }
            else { //Tentar melhorar indentação do output
                printf("| %-28s | %-13s | %-8s |\n", "NOME", "ANO-LANCAMENTO", "NOTA");

                aux = (Jogo*) sllGetFirst(jogos);

                if (aux != NULL) {
                    printf("| %-28s | %-13d | %-8.1f |\n", aux->name, aux->anoLancamento, aux->notaSteam);

                    for (int i = 1; i < sllSize(jogos); i++) {
                        aux = (Jogo*) sllGetNext(jogos);
                        printf("| %-28s | %-13d | %-8.1f |\n", aux->name, aux->anoLancamento, aux->notaSteam);
                    }
                    printf("-------------------------------------------------------------------------------\n");
                }
                else {
                printf("A lista esta vazia\n");
                }
            }
        }
        else if (opcao == 6) {
            if (jogos == NULL) {
                printf("\n>>>>>>>>>>Crie uma colecao primeiro<<<<<<<<<<\n");
            }
            else {
                result = sllEmpty(jogos);

                if (result == TRUE) {
                    printf("\n>>>>>>>>>>A lista foi esvaziada<<<<<<<<<<\n");
                }
                else {
                    printf("\n>>>>>>>>>>Falha ao esvaziar lista!<<<<<<<<<<\n");
                }
            }
        }
        else if (opcao == 7) {
            if (jogos == NULL) {
                printf("\n>>>>>>>>>>Crie uma lista primeiro<<<<<<<<<<\n");
            }
            else {
                result = sllDestroy(jogos);

                if (result == TRUE) {
                    printf("\n>>>>>>>>>>Lista destruida com sucesso<<<<<<<<<<\n");
                    jogos = NULL;
                }
                else {
                    printf("\n>>>>>>>>>>A Lista precisa estar vazia<<<<<<<<<<\n");
                }
            }
        }
        else {
            flagParada = FALSE;
            printf("Encerrando programa...\n");
        }
    }

    if (jogos != NULL) {
        sllEmpty(jogos);
        sllDestroy(jogos);
    }

    return 0;
}