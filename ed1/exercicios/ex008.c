#include <stdio.h>
#include "stack.h"

void prime_fact(Stack *stk, int num) {
    int i = 2, aux;
    while (num != 1) {
        while (num % i == 0) {
            push(stk, i);
            num /= i;
        }
        i++;
    }

    aux = pop(stk);
    while (aux != NULL) {
        aux = (int *) aux;
        printf("%d ", aux);
        aux = pop(stk);
    }
}

int main() {
    Stack *s;
    s = stkCreate(20);
    prime_fact(s, 520);
    return 0;
}