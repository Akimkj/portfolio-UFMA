#ifndef _STACK_C
#define _STACK_C
#include <stdlib.h>
#include "stack.h"

typedef struct _stack_ {
    int maxItens;
    int top;
    void **itens;
}Stack;

Stack *stkCreate(int maxItens) {
    Stack *s;
    if (maxItens > 0) {
        s = (Stack*) malloc(sizeof(Stack));
        if (s != NULL) {
            s->itens = (void**) malloc(sizeof(void*) * maxItens);
            if (s->itens != NULL) {
                s->maxItens = maxItens;
                s->top = -1;
                return s;
            }
        }
    }
    return NULL;
}

int stkDestroy(Stack *stk) {
    if (stk != NULL && stk->top < 0) {
        free(stk->itens);
        free(stk);
        return TRUE;
    }
    return FALSE;
}

int push(Stack *stk, void *data) {
    if (stk != NULL && stk->top < stk->maxItens - 1) {
        stk->top++;
        stk->itens[stk->top] = data;
        return TRUE;
    }
    return FALSE;
}

void *pop(Stack *stk) {
    void *aux;
    if (stk != NULL) {
        if (stk->top >= 0) {
            aux = stk->itens[stk->top];
            stk->top--;
            return aux;
        }
    }
    return NULL;
}


#endif