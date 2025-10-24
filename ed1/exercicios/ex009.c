#include <stdio.h>
#include "stack.h"
#include <stdlib.h>

void convDecBin(Stack *s, int num) {
    if (s == NULL) return;


    while (num > 0) {
        int *digit = malloc(sizeof(int));
        *digit = num % 2;
        push(s, digit);
        num /= 2;
    }

    void *temp;
    while ((temp = pop(s)) != NULL) {
        printf("%d", *(int*)temp);
        free(temp); // Libera a memória alocada
    }
}


int main() {
    Stack *stk;
    stk = stkCreate(16);
    if (stk != NULL) {
        convDecBin(stk, 77);
        stkDestroy(stk);
        return 0;
    }

    return 1;
}