#include <stdio.h>
#include <stdlib.h>

int maxProfit(int* preco, int size) {
    int diaInicio, diaFim;
    int precoinicio = preco[0], precoFim = preco[0];

    for (int i = 0; i < size; i++) {
        if (preco[i] < precoinicio) {
            precoinicio = preco[i];
            diaInicio = i;
        }
    }

    for (int j = 0; j < size; j++) {
        if (preco[j] > precoFim && diaFim > diaInicio) {
            precoFim = preco[j];
            diaFim = j;
        }
    }

    int lucro = precoFim - precoinicio;
    printf("Compre no dia %d (preco: %d) e venda no dia %d (preco %d), lucro = %d\n", diaInicio, precoinicio, diaFim, precoFim, lucro);
    return lucro;
}
int main() {
    int tam = 5;
    int *precos = malloc(tam * sizeof(int));
    
    for (int i = 0; i < tam; i++) {
        printf("Digite o preco %d: ", i+1);
        scanf("%d", &precos[i]);
    }

    maxProfit(precos,tam);
    return 0;
}