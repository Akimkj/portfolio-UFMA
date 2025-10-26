#ifndef _QUEUE_C
#define _QUEUE_C
#include <stdlib.h>
#include "queue.h"

typedef struct _qcqueue_ {
    int maxItens;
    int rear;
    int front;
    int numItens;
    void **itens;
} Queue;

Queue *qcCreate(int max) {
    Queue *q;
    if (max > 0) {
        q = (Queue*) malloc (sizeof(Queue));
        if (q != NULL) {
            q->itens = (void**) malloc (sizeof(void*) * max);
            if (q != NULL) {
                q->front = 0;
                q->rear = -1;
                q->numItens = 0;
                q->maxItens = max;
                return q;
            }
        }
    }
    return NULL;
}

int qcDestroy(Queue *q) {
    if (q != NULL) {
        if (q->numItens == 0) {
            free(q->itens);
            free(q);
            return TRUE;
        }
    }
    return FALSE;
}

int qcIncCirc(int pos, int maxItens) {
    if (pos < maxItens - 1) {
        return pos + 1;
    }
    else {
        return 0;
    }
}

int qcEnQueue(Queue *q, void *data) {
    if (q != NULL) {
        if (q->numItens < q->maxItens) {
            q->rear = qcIncCirc(q->rear, q->maxItens);
            q->itens[q->rear] = data;
            q->numItens++;
            return TRUE;
        }
    }
    return FALSE;
}

void *qcDeQueue(Queue *q) {
    void *aux;
    if (q != NULL) {
        if (q->numItens > 0) {
            aux = q->itens[q->front];
            q->front = qcIncCirc(q->front, q->maxItens);
            q->numItens--;
            return aux;
        }
    }
    return NULL;
}

#endif