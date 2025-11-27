#ifndef SLLIST_H
#define SLLIST_H

#define TRUE 1
#define FALSE 0

typedef struct _slnode_ SLnode;
typedef struct _sllist_ SLlist;


SLlist *sllCreate();

int sllDestroy(SLlist *l);

int sllInsertAsFirst(SLlist *l, void *data);

void *sllRemoveFirst(SLlist *l);

void *sllQueryLast(SLlist *l);

int sllSize(SLlist *l); // 2 - da lista de exercicio 2

int sllInsertAsLast(SLlist *l, void *data);

int sllInsertAfterFirst(SLlist *l, void *data);

void *sllQuery(SLlist *l, void *key, int (*cmp) (void*, void*));

int sllInsertAfterSpec(SLlist *l, void *key, int (*cmp) (void*, void*), void *data);

void *sllRemoveSpec(SLlist *l, void *key, int (*cmp) (void*, void*));

int sllInsertBeforeSpec(SLlist *l, void *key, int (*cmp) (void*, void*), void *data); // 1 - da lista de execicio 2

void *sllRemoveAfterSpec(SLlist *l, void *key, int (*cmp) (void*, void*)); // 3 - da lista de exercicio 2

void *sllRemoveBeforeSpec(SLlist *l, void *key, int (*cmp) (void*, void*)); // 4 - da lista de exercício 2

int csllInsertBeforeSpec(SLlist *l, void *key, int  (*cmp) (void*, void*), void *data);

void *sllGetFirst(SLlist *l);

void *sllGetNext(SLlist *l);

#endif