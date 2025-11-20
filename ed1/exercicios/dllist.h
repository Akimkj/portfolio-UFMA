#ifndef _DLLIST_H
#define _DLLIST_H

#define TRUE 1
#define FALSE 0
#define ERROR -1

typedef struct _dllist_ DLList;
typedef struct _dlnode_ DLNode;

DLList *dllCreate();

int dllDestroy(DLList *l);

int dllInsertAsFirst(DLList *l, void *data);

void *dllRemoveSpec(DLList *l, void *key, int (*cmp)(void*, void*));

//lista exDLL 1 - questao 1
int dllInsertAsLast(DLList *l, void *data);

//lista exDLL 1 - questao 2
int dllInsertAfterSpec(DLList *l, void *key, int (*cmp)(void*,void*), void *data);

//lista exDLL 1 - questao 3
int dllInsertBeforeSpec(DLList *l, void *key, int (*cmp)(void*,void*), void *data);

#endif