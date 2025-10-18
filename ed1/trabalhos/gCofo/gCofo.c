/*Arquivo com as implementações das operações sobre o Cofo / TAD Genérico*/

#ifndef _GCOFO_C
#define _GCOFO_C

#include <stdlib.h>
#include "gCofo.h"

// Função auxiliar para comparar strings
int cmp(char *str1, char *str2) {
    int i = 0;
    
    // Compara caractere por caractere
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return FALSE;
        }
        i++;
    }
    
    // Se ambos terminaram, são iguais
    if (str1[i] == str2[i]) {
        return TRUE;
    }
    
    return FALSE; 
}

Gcofo *GcofoCreate(int maxItens) {
    Gcofo *gc;
    if (maxItens > 0) {
        gc = (Gcofo*) malloc(sizeof(Gcofo));
        if (gc != NULL) {
            gc->itens = (Jogo**) malloc (sizeof(Jogo*) * maxItens);
            if (gc->itens != NULL) {
                gc->maxItens = maxItens;
                gc->numItens = 0;
                gc->cur = -1;
                return gc;
            }
            free(gc->itens);
        }
        free(gc);
    }
    return NULL;
}

int GcofoInsert(Gcofo *gcof, Jogo *item) {
    if (gcof != NULL) {
        if (gcof->numItens < gcof->maxItens) {
            gcof->itens[gcof->numItens] = item;
            gcof->numItens++;
            return TRUE;
        }
    }
    return FALSE;
}

int GcofoDestroy(Gcofo *gcof) {
    if (gcof != NULL) {
        if (gcof->numItens == 0) {
            free(gcof->itens);
            free(gcof);
            return TRUE;
        }
    }
    return FALSE;
}


int GcofoEmpty(Gcofo *gcof) {
    if (gcof != NULL) {
        // Libera todos os jogos armazenados
        for (int i = 0; i < gcof->numItens; i++) {
            if (gcof->itens[i] != NULL) {
                free(gcof->itens[i]);
            }
        }
        gcof->numItens = 0;
        return TRUE;
    }
    return FALSE;
}

Jogo *GcofoGetFirst(Gcofo *gcof) {
    if (gcof != NULL) {
        if (gcof->numItens > 0) {
            gcof->cur = 0;
            return gcof->itens[gcof->cur];
        }
    }
    return NULL;
}

Jogo *GcofoGetNext(Gcofo *gcof) {
    if (gcof != NULL) {
        if(gcof->cur < gcof->numItens - 1) {
            gcof->cur++;
            return gcof->itens[gcof->cur];
        }
    }
    return NULL;
}

int GcofoQuery(Gcofo *gcof, char *name) {
    int j, status;
    if (gcof != NULL && gcof->numItens > 0) {
        //para cada jogo
        for (int i = 0; i < gcof->numItens; i++) {
            //para cada letra dentro do nome do jogo
            j = 0;
            status = TRUE;
            while (gcof->itens[i]->name[j] != '\0' && name[j] != '\0' && status == TRUE) {
                if (gcof->itens[i]->name[j] != name[j]) {
                    status = FALSE;
                }
                j++;
            }

            if (status == TRUE && gcof->itens[i]->name[j] == '\0' && name[j] == '\0') {
                return TRUE;
            }
        }
    }
    return FALSE;
}


Jogo *GcofoRemove(Gcofo *gcof, char *name) {
    Jogo *removido;

    if (gcof != NULL && gcof->numItens > 0 && name != NULL) {
        for (int i = 0; i < gcof->numItens; i++) {
            if (gcof->itens[i] != NULL && 
                gcof->itens[i]->name != NULL && 
                cmp(gcof->itens[i]->name, name)) {
            
                removido = gcof->itens[i];
            
                // Remove o elemento
                for (int j = i; j < gcof->numItens - 1; j++) {
                    gcof->itens[j] = gcof->itens[j + 1];
                }
            
                gcof->itens[gcof->numItens - 1] = NULL;
                gcof->numItens--;
            
                return removido;
            }
        }   
    }
    return NULL;
}



#endif