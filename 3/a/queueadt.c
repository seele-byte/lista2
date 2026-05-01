#include <stdlib.h>
#include <stdio.h>
#include "queueadt.h"

#define MAX 100
typedef struct Queue
{
    int front;
    int rear;
    int count;
    int array[MAX];
} QUEUE;

QUEUE* create_queue()
{
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    if(!queue)
    {
        printf("Erro de alocação de memória!\n");
        return NULL;
    }
    queue->count = 0;
    queue->front = 0;
    queue->rear = 0;
    return queue;
}

static int fila_existe(QUEUE* queue)
{
    return queue != NULL;
}

int enqueue(QUEUE*queue,int val)
{
    if(!fila_existe(queue) || full_queue(queue)) return 0;
    queue->array[queue->rear] = val;
    queue->rear = (queue->rear+1)%MAX;
    queue->count++;
    return 1;
}
int dequeue(QUEUE*queue,int *dataoutptr)
{
    if(!fila_existe(queue) || empty_queue(queue)) return 0;
    *dataoutptr = queue->array[queue->front];
    queue->front = (queue->front+1)%MAX;
    queue->count--;
    return 1;
}
int queue_front (QUEUE*queue,int *dataout)
{
    if(!fila_existe(queue) || empty_queue(queue)) return 0;
    *dataout = queue->array[queue->front];
    return 1;
}
int queue_rear (QUEUE*queue, int* dataout)
{
    if(!fila_existe(queue) || empty_queue(queue)) return 0;
    *dataout = queue->array[(queue->rear-1+MAX)%MAX];//caso o rear seja 0 
    return 1;
}
void destroy_queue(QUEUE*queue)
{
    if(!fila_existe(queue)) return;
    free(queue);
}
int queue_size(QUEUE*queue)
{
    if(!fila_existe(queue)) return -1;
    return queue->count;
}
int empty_queue(QUEUE*queue)
{
    if(!fila_existe(queue)) return 1;
    return queue->count == 0;
}
int full_queue(QUEUE*queue)
{
    if(!fila_existe(queue)) return 0;
    return queue->count == MAX;
}
