#ifndef _STACK_H
#define _STACK_H

typedef struct _stack_ Stack;
#define TRUE 1
#define FALSE 0

Stack *stkCreate(int maxItens);

int stkDestroy(Stack *stk);

int push(Stack *stk, void *data);

void *pop(Stack *stk);

int RemoveMaioresQueKey(Stack *s, void *key, int (*cmp) 
(void *, void *));

#endif