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

int sllSize(SLlist *l);

int sllInsertAsLast(SLlist *l, void *data);

int sllInsertAfterFirst(SLlist *l, void *data);

#endif