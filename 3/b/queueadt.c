#include <stdlib.h>
#include <stdio.h>
#include "queueadt.h"

typedef struct stnode 
{
    int valor;
    struct stnode* prox;
}NODE;
typedef struct Queue 
{
    NODE* head;
    NODE* tail;
    int count;
} QUEUE;
QUEUE* create_queue()
{
    QUEUE* fila = (QUEUE*)malloc(sizeof(QUEUE));
    if(!fila)
    {
        printf("erro de alocação de memória\n");
        return NULL;
    }
    fila->count = 0;
    fila->head = NULL;
    fila->tail = NULL;
    return fila;
}
int enqueue(QUEUE*queue,int val)
{
    if(!queue) return 0;
    NODE* node = (NODE*)malloc(sizeof(NODE));
    if(!node) return 0;
    node->valor = val;
    node->prox = NULL;
    //se for o primeiro elemento na fila
    if (queue->head == NULL && queue->tail == NULL)
    {
        queue->head = queue->tail = node;
    }
    else 
    {
        queue->tail->prox = node;
        queue->tail = node;
    }
    queue->count++;
    return 1;
}
int dequeue(QUEUE*queue,int*dataoutptr)
{
    if(!queue || !dataoutptr || empty_queue(queue)) return 0;
    *dataoutptr = queue->head->valor;
    NODE* aux = queue->head;
    queue->head = queue->head->prox;
    free(aux);
    if(queue->head == NULL) queue->tail = NULL;
    queue->count--;
    return 1;
}
int queue_front (QUEUE*queue,int*dataoutptr)
{
    if(!queue || !dataoutptr || empty_queue(queue)) return 0;
    *dataoutptr = queue->head->valor;
    return 1;
}
int queue_rear (QUEUE*queue,int*dataoutptr)
{
    if(!queue || !dataoutptr || empty_queue(queue)) return 0;
    *dataoutptr = queue->tail->valor;
    return 1;
}
void destroy_queue(QUEUE*queue)
{
    if(!queue) return;
    while(queue->head != NULL)
    {
        NODE*temp = queue->head;
        queue->head = queue->head->prox;
        free(temp);
    }
    free(queue);
}
int queue_size(QUEUE*queue)
{
    if(!queue) return -1;
    return queue->count;
}
int empty_queue(QUEUE*queue)
{
    if(!queue) return 0;
    return queue->count == 0;
}