#include <stdio.h>
#include <stdlib.h>
#include "gCofo.h"


int main() {
    Jogo *hollowKnight;
    Jogo *subnautica;
    Jogo *silksong;

    hollowKnight = (Jogo*) malloc(sizeof(Jogo));
    subnautica = (Jogo*) malloc(sizeof(Jogo));
    silksong = (Jogo*) malloc(sizeof(Jogo));

    silksong->name = "Hollow Knight: Silksong";
    silksong->anoLancamento = 2025;
    silksong->notaSteam = 5.0;

    subnautica->name = "Subnautica";
    subnautica->anoLancamento = 2020;
    subnautica->notaSteam = 4.5;

    hollowKnight->name = "Hollow Knight";
    hollowKnight->anoLancamento = 2014;
    hollowKnight->notaSteam = 4.8;

    Gcofo *jogos;
    jogos = GcofoCreate(3);

    if(jogos == NULL) {
        printf("merda\n");
        return -1;
    }

    GcofoInsert(jogos, hollowKnight);
    GcofoInsert(jogos, subnautica);
    GcofoInsert(jogos, silksong);

    printf("JOGOS DO COFO:\n");
    printf("NOME\tLANÇAMENTO\tNOTA\n");
    
    Jogo *aux;
    aux = GcofoGetFirst(jogos);
    printf("%s\t%d\t%.2f\n", aux->name, aux->anoLancamento, aux->notaSteam);
    for (int i = 0; i < jogos->numItens -1; i++) {
        aux = GcofoGetNext(jogos);
        printf("%s\t%d\t%.2f\n", aux->name, aux->anoLancamento, aux->notaSteam);
    }

    
    return 0;
}