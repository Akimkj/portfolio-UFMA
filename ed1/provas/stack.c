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


/*Faça um algoritmo que recebe uma pilha armazenada em um 
vetor, um valor (chave), e uma função de comparação, e remove 
respeitando a disciplina de acesso da pilha todos os elementos até 
encontrar um com chave menor que o valor da chave recebida. 
Não pode usar pops e push, e deve obedecer a disciplina de 
acesso da pilha. É uma função interna do TAD Pilha. 
int RemoveMaioresQueKey (Stack *s, void *key, int (*cmp) 
(void *, void *)) 
OBS: cmp (a,b) retorna TRUE se a < b e False caso contrário */
int RemoveMaioresQueKey(Stack *s, void *key, int (*cmp) 
(void *, void *)) {
    int count = 0;
    if (s != NULL) {
        if (s->top >= 0) {
            while (s->top >= 0 && !cmp(s->itens[s->top], key)) {
                s->top--;
                count++;
            }
        }
    }
    return count;
}


#endif