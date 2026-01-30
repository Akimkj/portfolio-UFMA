#ifndef _DLLIST_C
#define _DLLIST_C

#include <stdlib.h>
#include "dllist.h"

typedef struct _dlnode_ {
    struct _dlnode_ *prev, *next;
    void *data;
} DLNode;

typedef struct _dllist_ {
    DLNode *first;
} DLList;


DLList *dllCreate() {
    DLList *l;
    l = (DLList*) malloc(sizeof(DLList));
    if (l != NULL) {
        l->first = NULL;
        return l;
    }
    return NULL;
}

int dllDestroy(DLList *l) {
    if (l != NULL) {
        if (l->first != NULL) {
            free(l);
            return TRUE;
        }
    }
}

int dllInsertAsFirst(DLList *l, void *data) {
    DLNode *newnode;
    if (l != NULL) {
        newnode = (DLNode*) malloc (sizeof(DLNode));
        if (newnode != NULL) {
            newnode->data = data;
            newnode->prev = NULL;
            newnode->next = l->first;
            if (l->first != NULL) {
                (l->first)->prev = newnode;
            }
            l->first = newnode;
            return TRUE;
        }
    }
    return FALSE;
}

void *dllRemoveSpec(DLList *l, void *key, int (*cmp)(void*, void*)) {
    DLNode *spec, *prev, *next;
    void *data;
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
                data = spec->data;
                prev = spec->prev;
                next = spec->next;

                if (prev != NULL) {
                    prev->next = next;
                }
                else {
                    l->first = next;
                }

                if (next != NULL) {
                    next->prev = prev;
                }

                free(spec);
                return data;
            }
        }
    }
    return NULL;
}

int dllInsertAsLast(DLList *l, void *data) {
    DLNode *newnode, *last;

    if (l != NULL) {
        newnode = (DLNode*) malloc (sizeof(DLNode));
        if (newnode != NULL) {
            newnode->data = data;
            newnode->next = NULL;
            if (l->first != NULL) {
                last = l->first;
                while (last->next != NULL) {
                    last = last->next;
                }
                newnode->prev = last;
                last->next = newnode;
            }
            else {
                newnode->prev = NULL;
                l->first = newnode;
            }
            return TRUE;
        }
    }
    return FALSE;
}

int dllInsertAfterSpec(DLList *l, void *key, int (*cmp)(void*,void*), void *data) {
    DLNode *spec, *newnode, *next;
    int stat;

    if (l != NULL) {
        if (l->first != NULL) {
            spec = l->first;
            stat = cmp(key, spec->data);

            while (spec->next != NULL && stat != TRUE) {
                spec = spec->next;
                stat = cmp(key, spec->data);
            }
            if (stat == TRUE) {
                newnode = (DLNode*) malloc(sizeof(DLNode));
                if (newnode != NULL) {
                    next = spec->next;

                    newnode->data = data;
                    newnode->prev = spec;
                    spec->next = newnode;

                    if (next != NULL) {
                        next->prev = newnode;
                    }

                    newnode->next = next;
                    return TRUE;

                }
            }
        }
    }
    return FALSE;
}

int dllInsertBeforeSpec(DLList *l, void *key, int (*cmp)(void*,void*), void *data) {
    DLNode *spec, *newnode, *prev;
    int stat;

    if (l != NULL) {
        if (l->first != NULL) {
            spec = l->first;
            stat = cmp(key, spec->data);

            while (spec->next != NULL && stat != TRUE) {
                spec = spec->next;
                stat = cmp(key, spec->data);
            }
            if (stat == TRUE) {
                newnode = (DLNode*) malloc(sizeof(DLNode));
                if (newnode != NULL) {
                    prev = spec->prev;

                    newnode->data = data;
                    newnode->next = spec;
                    spec->prev = newnode;
                    newnode->prev = prev;
                    
                    if (prev != NULL) {
                        prev->next = newnode;
                    }
                    else {
                        l->first = newnode;
                    }

                    return TRUE;

                }
            }
        }
    }
    return FALSE;
}

int cdllInsertBeforeSpec(DLList *l, void *key, int (*cmp)(void*,void*), void *data) {
    DLNode *spec, *newnode, *prev;
    int stat;

    if (l != NULL) {
        if (l->first != NULL) {
            spec = l->first;
            stat = cmp(key, spec->data);

            while (spec->next != l->first && stat != TRUE) {
                spec = spec->next;
                stat = cmp(key, spec->data);
            }
            if (stat == TRUE) {
                newnode = (DLNode*) malloc(sizeof(DLNode));
                if (newnode != NULL) {
                    prev = spec->prev;

                    newnode->data = data;
                    newnode->next = spec;
                    spec->prev = newnode;
                    newnode->prev = prev;
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


/*int InverteLista(DLList *l1) {
    DLNode *spec, *prev, *next;

    if (l1 != NULL) {
        if (l1->first != NULL) {
            spec = l1->first;
            next = spec->next;
            while (spec != NULL) {
                prev = spec->prev;

                spec->prev = next;
                spec->next = prev;


                spec = next;
                if (next != NULL) {
                    next = next->next;
                }
                else {
                    l1->first = prev;
                }
            }
            return TRUE;
        }
    }
    return FALSE;
}*/



/*Inverter lista numa ddlist - TESTADO*/
int InverteLista(DLList *l1) {
    DLNode *spec, *prev, *next;

    if (l1 != NULL) {
        if (l1->first != NULL) {
            spec = l1->first;
            prev = spec->prev;
            
            while (spec->next != NULL) {
                next = spec->next;

                spec->prev = next;
                spec->next = prev;

                prev = spec;
                spec = next;
            }
            next = spec->next;
            spec->prev = next;
            spec->next = prev;
            l1->first = spec;
            return TRUE;
        }
    }
    return FALSE;
}


/*União de duas listas (com repetição)*/
DLList *UniaoLista(DLList *l1, DLList *l2) {
    DLNode *spec1;

    if (l1 != NULL && l2 != NULL) {
        if (l1->first == NULL) {
            return l2;
        }
        if (l2->first == NULL) {
            return l1;
        }

        spec1 = l1->first;


        while (spec1->next != NULL) {
            spec1 = spec1->next;
        }

        (l2->first)->prev = spec1;
        spec1->next = l2->first;

        return l1;
    }
    return NULL;
}

DLList *CortarLista(DLList *l1, void *key, int (*cmp)(void*,void*)) {
    DLList *l2;
    DLNode *spec;
    int stat;

    if (l1 != NULL) {
        if (l1->first != NULL) {
            spec = l1->first;
            stat = cmp(key, spec->data);
            while (spec->next != NULL && stat != TRUE) {
                spec = spec->next;
                stat = cmp(key, spec->data);
            }
            if (stat == TRUE) {
                l2 = (DLList*) malloc(sizeof(DLList));
                if (l2 != NULL) {
                    if (spec->next != NULL) {
                        l2->first = spec->next;
                        (l2->first)->prev = NULL;
                    }
                    else {
                        l2->first = NULL;
                    }
                    spec->next = NULL;
                    return l2;
                }
            }
        }
    }
    return NULL;
}

#endif