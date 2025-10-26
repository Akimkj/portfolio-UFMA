#ifndef _QUEUE_H
#define _QUEUE_H

typedef struct _qcqueue_ Queue;
#define TRUE 1
#define FALSE 0

Queue *qcCreate(int max);
int qcDestroy(Queue *q);
int qcEnQueue(Queue *q, void *data);
void *qcDeQueue(Queue *q);
int qcIncCirc(int pos, int maxItens);


#endif