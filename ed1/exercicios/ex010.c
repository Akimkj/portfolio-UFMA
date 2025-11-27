#include <stdio.h>
#include "sllist.h"
#include <stdlib.h>

int cmp(void *a, void *b) {
    int *aInt = (int*) a;
    int *bInt = (int*) b;

    if (*aInt == *bInt) {
        return TRUE;
    }
    return FALSE;
}

int main() {
    int *data_2 = (int*) malloc(sizeof(int));
    *data_2 = 2; // Armazena o valor 2 no endereço de memória alocado
    
    int *data_7 = (int*) malloc(sizeof(int));
    *data_7 = 7;



    SLlist *l;
    SLnode *node;
    l = sllCreate();

    sllInsertAsFirst(l, (void*) data_2);
    csllInsertBeforeSpec(l, (void*) data_2, cmp, (void *) data_7);


    node = sllGetFirst(l);
    int *valorNode = (int*) node;
    printf("%d ", *valorNode);

    sllDestroy(l);

    return 0;
}