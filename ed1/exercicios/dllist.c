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

#endif