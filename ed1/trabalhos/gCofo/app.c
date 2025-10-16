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
                printf("\n\tUma colecao ja esta criada\n");
            }
            else {
                printf("Digite o tamanho maximo da colecao: ");
                scanf("%d", &tamMax);
                jogos = GcofoCreate(tamMax);
                if (jogos != NULL) {
                    printf("\n\tCOLECAO CRIADA!\n");
                }
                else {
                    printf("\n\tFalha ao criar colecao!\n");
                }
            }
        }
        else if (opcao == 2) {
            if (jogos == NULL) {
                printf("\n\tPrimeiramente, crie uma colecao\n");
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
                        printf("\n\tJogo Inserido com Sucesso!\n");
                    }
                    else {
                        printf("\n\tColecao ja esta cheia!!!\n");
                    }
                }
                else {
                        printf("\n\tFalha ao inserir jogo na colecao\n");
                }
            }
        }
        else if (opcao == 3) { 
            if (jogos == NULL) {
                printf("\n\tPrimeiramente, crie uma colecao\n");
            }
            else {
                char jogoRemover[100];
                Jogo *jogoRemovido;
                getchar();
                printf("Digite o nome do jogo que deseja remover: ");
                scanf("%100[^\n]", jogoRemover);

                jogoRemovido = GcofoRemove(jogos, jogoRemover);

                if (jogoRemovido != NULL) {
                    printf("\n\tJogo removido com sucesso: ");
                    printf("\n\tNome: %s | Ano lancamento: %d | Nota: %.1f \n", jogoRemovido->name, jogoRemovido->anoLancamento, jogoRemovido->notaSteam);
                }
                else {
                    printf("\n\tNão foi possivel localizar este jogo na colecao\n");
                }
            }
        }
        else if (opcao == 4) {
            if (jogos == NULL) {
                printf("\n\tCrie uma colecao primeiro\n");
            }
            else {
                char nomeProcurar[100];
                getchar();
                printf("Digite o nome do jogo que deseja achar: ");
                scanf("%100[^\n]", nomeProcurar);

                result = GcofoQuery(jogos, nomeProcurar);

                if (result == TRUE) {
                    printf("\n\tElemento encontrado!\n");
                }
                else {
                    printf("\n\tElemento nao esta presente na colecao!\n");
                }
            }
        }
        else if (opcao == 5) {
            if (jogos == NULL) {
                printf("\n\tCrie uma colecao primeiro\n");
            }
            else { //Tentar melhorar indentação do output
                printf("NOME \t ANO-LANCAMENTO   NOTA\n");
                aux = GcofoGetFirst(jogos);
                if (aux != NULL) {
                    printf("\n%s \t %d \t %.1f\n", aux->name, aux->anoLancamento, aux->notaSteam);

                    for (int i = 1; i < jogos->numItens; i++) {
                        aux = GcofoGetNext(jogos);
                        printf("\n%s \t %d \t %.1f\n", aux->name, aux->anoLancamento, aux->notaSteam);
                    }
                }
                else {
                printf("A colecao esta vazia\n");
                }
            }
        }
        else if (opcao == 6) {
            if (jogos == NULL) {
                printf("\n\tCrie uma colecao primeiro\n");
            }
            else {
                result = GcofoEmpty(jogos);

                if (result == TRUE) {
                    printf("\n\tA colecao foi esvaziada\n");
                }
                else {
                    printf("\n\tFalha ao esvaziar a colecao!\n");
                }
            }
        }
        else if (opcao == 7) {
            if (jogos == NULL) {
                printf("\n\tCrie uma colecao primeiro\n");
            }
            else {
                result = GcofoDestroy(jogos);

                if (result == TRUE) {
                    printf("\n\tColecao destruida com sucesso\n");
                    jogos = NULL;
                }
                else {
                    printf("\n\tA colecao precisa estar vazia\n");
                }
            }
        }
        else {
            flagParada = FALSE;
            printf("Encerrando programa...");
        }
    }

    if (jogos != NULL) {
        free(jogos->itens);
        free(jogos);
    }

    return 0;
}