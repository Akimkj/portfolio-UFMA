/*
Arquivo que contém a implementação das funções das operações do TAD CofoInt
*/
#ifndef __COFOINT_C
#define __COFOINT_C
#include "CofoInt.h"
#include <stdlib.h>

typedef struct __cofo__ {
    int maxItens;
    int numItens;
    int *item;
}CofoInt;

CofoInt *CreateCofoInt(int maxItens) {
    CofoInt *cof;
    if (maxItens > 0) {
        cof = (CofoInt*) malloc(sizeof(CofoInt));
        if (cof != NULL) {
            cof->maxItens = maxItens;
            cof->numItens = 0;
            cof->item = (int*) malloc(sizeof(int) * maxItens);
            if (cof->item != NULL) {
                return cof;
            }
            free(cof->item);
        }
        free(cof);
    }
    return NULL;
}


int CofoIntQuery(CofoInt *cof, int key) {
     if (cof != NULL && cof->numItens > 0) {
        for (int i = 0; i < cof->numItens; i++) {
            if (cof->item[i] == key) {
                return i;
            }
        }
     }
     return ERROR;
}



int CofoIntInsert(CofoInt *cof, int item) {
    if (cof != NULL && cof->numItens < cof->maxItens) {
        cof->item[cof->numItens] = item;
        cof->numItens++;
        return TRUE;
    }
    return FALSE;
}


int CofoIntRemove(CofoInt *cof, int item) {
    if (cof != NULL && cof->numItens > 0) {
        int iquery, aux;
        iquery = CofoIntQuery(cof, item);
        if (iquery != ERROR) {
            aux = cof->item[iquery];
            for (int j = iquery; j < cof->numItens-1; j++) {
                cof->item[j] = cof->item[j+1];
            }
            cof->numItens--;
            return aux;
        }
    }
    return ERROR;
}


int CofoIntEmpty(CofoInt *cof) {
    if (cof != NULL) {
        cof->numItens = 0;
        return TRUE;
    }
    return FALSE;
}


int CofoIntDestroy(CofoInt *cof) {
    if (cof != NULL && cof->numItens == 0) {
         free(cof->item);
         free(cof);
         return TRUE;
    }
    return FALSE;
} 



int getMaxItens(CofoInt *cof) {
    if (cof != NULL) {
         return cof->maxItens;
    }
    return -1;
}


int getNumItens(CofoInt *cof) {
    if (cof != NULL) {
        return cof->numItens;
    }
    return -1;
}

int CofoIntGet(CofoInt *cof, int pos) {
    if (cof != NULL && pos >= 0 && pos < cof->numItens) {
        return cof->item[pos]; 
    }
    return ERROR;
}



#endif