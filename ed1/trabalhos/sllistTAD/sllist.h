#ifndef _SLLIST_H
#define _SLLIST_H
/*
* gcc -g app.c sllist.c -o app
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

/*Esvazia a lista*/
int sllEmpty(SLList *l);

/*Determina tamanho da lista*/
int sllSize(SLList *l);

/*Insere como ultimo elemento*/
int sllInsertAsLast(SLList *l, void *data);

/*Remove spec*/
void *sllRemoveSpec(SLList *l, void *key, int (*cmp) (void*, void*));

/*Remove o primeiro elemento*/
void *sllRemoveFirst(SLList *l); 

/*Procura por Query na lista*/
int sllQuery(SLList *l, void *key, int (*cmp) (void*, void*));

/*Primeira iteração da lista*/
void *sllGetFirst(SLList *l);

/*Iteração dos próximos nós da lista*/
void *sllGetNext(SLList *l);

#endif
