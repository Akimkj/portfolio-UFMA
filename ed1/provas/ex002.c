#include <stdio.h>
#include "queue.h"
#include <stdlib.h>
/*
Faça um algoritmo que recebe uma fila implementada como 
um vetor circular e remove todos os elementos de ordem par 
(segundo, quarto, sexto, etc.) Não pode utilizar um vetor auxiliar 
ou outra estrutura de dados. 
int RemoveElementosOrdemParFilaCircular (Queue *q, int n)
*/

void mostrarNovaFila(Queue *q, int n) {
    for (int i = 0; i < n; i++) {
        void *aux = qcDeQueue(q);
        printf("%c ", aux);
    }
}

int RemoveElementosOrdemParFilaCircular(Queue *q, int n) {
    int pos;
    if (q != NULL && n > 0) {
        for(pos = 0; pos < n; pos++) {
            if (pos % 2 == 0) {
                qcDeQueue(q);
                qcEnQueue(q, NULL);
            }
            else {
                qcEnQueue(q, qcDeQueue(q));
            }
        }
        return TRUE;
    }
    return FALSE;
}

int main() {
    Queue *qc;
    int MAX = 7;
    qc = qcCreate(MAX);
    if (qc == NULL) {
        printf("nao deu certo a criacao\n");
        return -1;
    }


    char *letra;
    letra = (char*) malloc (sizeof(char));
    for (int i = 0; i < MAX; i++) {
        printf("Digite uma letra para a fila: ");
        scanf("%c", &letra);

        qcEnQueue(qc, letra);
        getchar();
    }

    int value = RemoveElementosOrdemParFilaCircular(qc, MAX);

    if (value == TRUE) {
        printf("Deu certo!\n");
        mostrarNovaFila(qc, MAX);
    }
    else {
        printf("Deu errado\n");
    }

    return 0;
}