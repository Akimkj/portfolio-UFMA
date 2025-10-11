#include <stdio.h>
#include <stdlib.h>
#include "CofoInt.h"

int main() {
    CofoInt *cof;
    cof = CreateCofoInt(12);
    if (cof != NULL) {
        printf("Tamanho do cofo: %d\n", getMaxItens(cof));

        CofoIntInsert(cof, 12);
        CofoIntInsert(cof, -45);
        CofoIntInsert(cof, 78);
        CofoIntInsert(cof, 22);
        CofoIntInsert(cof, 2);
        CofoIntInsert(cof, 145);
        CofoIntInsert(cof, 67);
        CofoIntInsert(cof, -52);
        CofoIntInsert(cof, 1);
        
        for (int i = 0; i < getNumItens(cof); i++) {
            printf("%d ", CofoIntGet(cof, i));
        }
        printf("\n\n");

        CofoIntRemove(cof, -45);
        CofoIntRemove(cof, 145);
        CofoIntRemove(cof, 22);

        for (int i = 0; i < getNumItens(cof); i++) {
            printf("%d ", CofoIntGet(cof, i));
        }
        printf("\n\n");

        CofoIntEmpty(cof);
        CofoIntDestroy(cof);

        return 0;
    }
    free(cof);
    return -1; 
}