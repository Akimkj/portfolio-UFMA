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
            count = 0;
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
    SLnode *nodeFirst;
    if (l != NULL) {
        if (l->first != NULL) {
            newnode = (SLnode*) malloc(sizeof(SLnode));
            if (newnode != NULL) {
                nodeFirst = l->first;
                newnode->data = data;
                newnode->next = nodeFirst->next;
                nodeFirst->next = newnode;
                return TRUE;
            }
        }
    }
    return FALSE;
}

#endif