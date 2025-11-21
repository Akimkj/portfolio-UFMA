#ifndef _SLLIST_H
#define _SLLIST_H
/*
* gcc -g app.c gCofo.c -o app
* ./app.exe
*/
typedef struct _slnode_ SLNode;
typedef struct _sllist_ SLList;

typedef struct _jogo_ {
    char name[100];
    int anoLancamento;
    float notaSteam;
}Jogo;


#define TRUE 1
#define FALSE 0

/*Cria uma nova lista vazia*/
SLList *sllCreate();

/*Destroi uma lista quando vazia*/
int sllDestroy(SLList *l);

/*Determina se a lista está vazia ou não*/
int sllIsEmpty(SLList *l);

/*Determina tamanho da lista*/
int sllSize(SLList *l);

/*Insere como primeiro elemento*/
int sllInsertAsFirst(SLList *l, void *data);

/*Insere como ultimo elemento*/
int sllInsertAsLast(SLList *l, void *data);

/*Insere depois de spec*/
int sllInsertAfterSpec(SLList *l, void *key, int (*cmp) (void*, void*), void *data);

/*Insere antes de spec*/
int sllInsertBeforeSpec(SLList *l, void *key, int (*cmp) (void*, void*), void *data);

/*Remove spec*/
void *sllRemoveSpec(SLList *l, void *key, int (*cmp) (void*, void*));

/*Remove o primeiro elemento*/
void *sllRemoveFirst(SLList *l);

/*Remove depois spec*/
void *sllRemoveAfterSpec(SLList *l, void *key, int (*cmp) (void*, void*));

/*Remove antes de spec*/
void *sllRemoveBeforeSpec(SLList *l, void *key, int (*cmp) (void*, void*));

#endif
