#ifndef SLLIST_C
#define SLLIST_C

#include <stdlib.h>
#include "sllist.h"

typedef struct _slnode_ {
    void *data;
    struct _slnode_ *next;
}SLnode;

typedef struct _sllist_ {
    SLnode *first;
}SLlist;

SLlist *sllCreate() {
    SLlist *l;
    l = (SLlist *) malloc (sizeof(SLlist));
    if (l != NULL) {
        l ->first = NULL;
        return l;
    }
    return NULL;
}

int sllDestroy(SLlist *l) {
    if (l != NULL) {
        if (l->first == NULL) {
            free(l);
            return TRUE;
        }
    }
    return FALSE;
}

int sllInsertAsFirst(SLlist *l, void *data) {
    SLnode *newnode;
    if (l != NULL) {
        newnode = (SLnode*) malloc(sizeof(SLnode));
        if (newnode != NULL) {
            newnode->data = data;
            newnode->next = l->first;
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}

void *sllRemoveFirst(SLlist *l) {
    void *data;
    SLnode *node;
    if (l != NULL) {
        if (l->first != NULL) {
            node = l->first;
            data = node->data;
            l->first = node->next;
            free(node);
            return data;
        }
    }
    return NULL;
}

void *sllQueryLast(SLlist *l) {
    SLnode *last;
    if (l != NULL) {
        if (l->first != NULL) {
            last = l->first;
            while (last->next != NULL) {
                last = last->next;
            }
            return last->data;
        }
    }
    return NULL;
}

int sllSize(SLlist *l) {
    SLnode *last;
    int count;
    if (l != NULL) {
        if (l->first != NULL) {
            count = 1;
            last = l->first;
            while (last->next != NULL) {
                count++;
                last = last->next;
            }
            return count;
        }
    }
    return 0;
}

int sllInsertAsLast(SLlist *l, void *data) {
    SLnode *newnode;
    SLnode *last;
    if (l != NULL) {
        newnode = (SLnode*) malloc(sizeof(SLnode));
        if (newnode != NULL) {
            newnode->data = data;
            newnode->next = NULL;
            if (l->first != NULL) {
                last = l->first;
                while (last->next != NULL) {
                    last = last->next;
                }
                last->next = newnode;
            }
            else {
                l->first = newnode;
            }
            return TRUE;
        }
    }
    return FALSE;
}

int sllInsertAfterFirst(SLlist *l, void *data) {
    SLnode *newnode;
    SLnode *spec;
    if (l != NULL) {
        if (l->first != NULL) {
            newnode = (SLnode*) malloc(sizeof(SLnode));
            if (newnode != NULL) {
                spec = l->first;
                newnode->data = data;
                newnode->next = spec->next;
                spec->next = newnode;
                return TRUE;
            }
        }
    }
    return FALSE;
}

void *sllQuery(SLlist *l, void *key, int (*cmp) (void*, void*)) {
    SLnode *spec;
    int stat;

    if (l != NULL) {
        if (l->first != NULL) {
            spec = l->first;
            stat = cmp(key, spec->data);
            while (stat != TRUE && spec->next != NULL) {
                spec = spec->next;
                stat = cmp(key, spec->data);
            }
            if (stat == TRUE) {
                return spec->data;
            }
        }
    }
    return NULL;
}

int sllInsertAfterSpec(SLlist *l, void *key, int (*cmp) (void*, void*), void *data) {
    SLnode *newnode, *spec;
    int stat;

    if (l != NULL) {
        if (l->first != NULL) {
            spec = l->first;
            stat = cmp(key, spec->data);
            while(stat != TRUE && spec->next != NULL) {
                spec = spec->next;
                stat = cmp(key, spec->data);
            }
            if(stat == TRUE) {
                newnode = (SLnode*) malloc(sizeof(SLnode));
                if (newnode != NULL) {
                    newnode->data = data;
                    newnode->next = spec->next;
                    spec->next = newnode;
                    return TRUE;
                }
            }
        } 
    }
    return FALSE;
}


void *sllRemoveSpec(SLlist *l, void *key, int (*cmp) (void*, void*)) {
    SLnode *spec, *prev;
    void *data;
    int stat;
    if (l != NULL) {
        if (l->first != NULL) {
            prev = NULL;
            spec = l->first;
            stat = cmp(key, spec->data);
            while (stat != TRUE && spec->next != NULL) {
                prev = spec;
                spec = spec->next;
                cmp(key, spec->data);
            }
            if (stat == TRUE) {
                if (prev != NULL) {
                    prev->next = spec->next;
                }
                else {
                    l->first = spec->next;
                }

                data = spec->data;
                free(spec); // a gente não libera necessáriamente o spec em si, mas sim o contéudo onde spec está enviando
                return data;
            }
        }
    }
    return NULL;
}


int sllInsertBeforeSpec(SLlist *l, void *key, int (*cmp) (void*, void*), void *data) {
    SLnode *spec, *newnode, *prev;
    int stat;

    if (l != NULL) {
        if (l->first != NULL) {
            prev = NULL;
            spec = l->first;
            stat = cmp(key, spec->data);
            while(stat != TRUE && spec->next != NULL) {
                prev = spec;
                spec = spec->next;
                stat = cmp(key, spec->data);
            }
            if (stat == TRUE) {
                newnode = (SLnode*) malloc(sizeof(SLnode));
                if (newnode != NULL) {
                    newnode->data = data;
                    newnode->next = spec;
                    if (prev != NULL) {
                        prev->next = newnode;
                    }
                    else { // se prev for NULL, é pq spec é o primeiro elemento., e agora será o segundo
                        l->first = newnode;
                    }
                    return TRUE;
                }
            }
        }
    }
    return FALSE;
}

/*usaremos apenas o spec para percorrer a lista, caso achemos spec, aí sim atribuimos uma variavel chamada next

podemos fazer isso, ao invés de fazer com que o next também percorra a lista, de forma confusa
*/
void *sllRemoveAfterSpec(SLlist *l, void *key, int (*cmp) (void*, void*)) {
    void *data;
    int stat;
    SLnode *spec, *next;

    if (l != NULL) {
        if (l->first != NULL) {
            spec = l->first;
            stat = cmp(key, spec->data);
            while (stat != TRUE && spec->next != NULL) {
                spec = spec->next;
                stat = cmp(key, spec->data);
            }
            if (stat == TRUE) {
                next = spec->next;
                if (next != NULL) { //só posso remover o proximo se existir o proximo
                    data = next->data;
                    spec->next = next->next;
                    free(next);
                    return data;
                }
            }
        }
    }
    return NULL;
}

void *sllRemoveBeforeSpec(SLlist *l, void *key, int (*cmp) (void*, void*)) {
    void *data;
    int stat;
    SLnode *spec, *prev, *beforePrev;

    if (l != NULL) {
        if (l->first != NULL) {
            spec = l->first;
            beforePrev = NULL;
            prev = NULL;
            stat = cmp(key, spec->data);
            while (stat != TRUE && spec->next != NULL) {
                beforePrev = prev;
                prev = spec;
                spec = spec->next;
                stat = cmp(key, spec->data);
            }
            if (stat == TRUE) {
                if (prev != NULL) { //so podemos remover o anterior se o anterior existir
                    data = prev->data;
                    if (beforePrev != NULL) {
                        beforePrev->next = spec;
                    }
                    else {
                        l->first = spec; // se chegou aqui, significa que spec é, obrigatoriamente, o segundo elemento da lista, e agora será o primeiro
                    }
                    free(prev);
                    return data;
                }
            }
        }
    }
    return NULL;
}

int csllInsertBeforeSpec(SLlist *l, void *key, int  (*cmp) (void*, void*), void *data) {
    SLnode *prev, *spec, *newnode;
    int stat;

    if (l != NULL) {
        if (l->first != NULL) {
            prev = l->first;
            spec = prev->next;
            stat = cmp(key, spec->data);
            while (stat != TRUE && spec != l->first ) {
                prev = spec;
                spec = spec->next;
                stat = cmp(key, spec->data);
            }
            if (stat == TRUE) {
                newnode = (SLnode*) malloc (sizeof(SLnode));
                if (newnode != NULL) {
                    newnode->data = data;
                    newnode->next = spec;
                    prev->next = newnode;
                    if (spec == l->first) {
                        l->first = newnode;
                    }
                    return TRUE;
                }
            } 
        }
    }
    return FALSE;
}



#endif