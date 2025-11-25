#ifndef _SLLIST_C
#define _SLLIST_C

#include <stdlib.h>
#include "sllist.h"

typedef struct _slnode_ {
    void *data;
    struct _slnode_ *next;
}SLNode;

typedef struct _sllist_ {
    SLNode *first, *current;
}SLList;

SLList *sllCreate() {
    SLList *l;
    l = (SLList *) malloc (sizeof(SLList));
    if (l != NULL) {
        l ->first = NULL;
        return l;
    }
    return NULL;
}

int sllDestroy(SLList *l) {
    if (l != NULL) {
        if (l->first == NULL) {
            free(l);
            return TRUE;
        }
    }
    return FALSE;
}

int sllEmpty(SLList *l) {
    if (l != NULL) {
        if (l->first != NULL) {
            free(l->first);
            l->first = NULL;
            return TRUE;
        }
    }
    return FALSE;
}

int sllSize(SLList *l) {
    SLNode *last;
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

int sllInsertAsFirst(SLList *l, void *data) {
    SLNode *newnode;
    if (l != NULL) {
        newnode = (SLNode*) malloc(sizeof(SLNode));
        if (newnode != NULL) {
            newnode->data = data;
            newnode->next = l->first;
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}

int sllInsertAsLast(SLList *l, void *data) {
    SLNode *newnode;
    SLNode *last;
    if (l != NULL) {
        newnode = (SLNode*) malloc(sizeof(SLNode));
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

int sllInsertAfterSpec(SLList *l, void *key, int (*cmp) (void*, void*), void *data) {
    SLNode *newnode, *spec;
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
                newnode = (SLNode*) malloc(sizeof(SLNode));
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

int sllInsertBeforeSpec(SLList *l, void *key, int (*cmp) (void*, void*), void *data) {
    SLNode *spec, *newnode, *prev;
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
                newnode = (SLNode*) malloc(sizeof(SLNode));
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

void *sllRemoveSpec(SLList *l, void *key, int (*cmp) (void*, void*)) {
    SLNode *spec, *prev;
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

void *sllRemoveFirst(SLList *l) {
    void *data;
    SLNode *node;
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

void *sllRemoveAfterSpec(SLList *l, void *key, int (*cmp) (void*, void*)) {
    void *data;
    int stat;
    SLNode *spec, *next;

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

void *sllRemoveBeforeSpec(SLList *l, void *key, int (*cmp) (void*, void*)) {
    void *data;
    int stat;
    SLNode *spec, *prev, *beforePrev;

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

int sllQuery(SLList *l, void *key, int (*cmp) (void*, void*)) {
    SLNode *spec;
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
                return TRUE;
            }
        }
    }
    return FALSE;
}

void *sllGetFirst(SLList *l) {
    if (l != NULL) {
        if (l->first != NULL) {
            l->current = l->first;
            return (l->first)->data;
        }
    }
    return NULL;
}

void *sllGetNext(SLList *l) {
    if (l != NULL) {
        if (l->current != NULL && l->current->next != NULL) {
            l->current = (l->current)->next;
            return (l->current)->data;
        }
    }
    return NULL;
}

#endif