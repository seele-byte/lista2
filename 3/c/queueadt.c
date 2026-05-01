#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queueadt.h"

typedef struct stNode 
{
    void* dataptr;
    size_t size;
    struct stNode* next;
}NODE;
typedef struct Queue
{
    NODE* head;
    NODE* rear;
    int count;
    
} QUEUE;
QUEUE* create_queue()
{
    QUEUE* queue = (QUEUE*)malloc(sizeof(QUEUE));
    if(!queue) return NULL;
    queue->count = 0;
    queue->head = NULL;
    queue->rear = NULL;
    return queue;
}
int enqueue(QUEUE*queue,void* datainPtr,size_t size)
{
    if(!queue || !datainPtr) return 0;
    NODE* node = (NODE*)malloc(sizeof(NODE));
    if(!node) return 0;
    node->dataptr = malloc(size);
    if (!node->dataptr)
    {
        free(node);
        return 0;
    }
    memcpy(node->dataptr,datainPtr,size);
    node->size = size;
    node->next = NULL;
    if(queue->head == NULL && queue->rear == NULL)
    {
        queue->head = node;
        queue->rear = node;
    }
    else
    {
        queue->rear->next = node;
        queue->rear = node;
    }
    queue->count++;
    return 1;
}
int dequeue(QUEUE*queue,void*dataoutPtr)
{
    if(!queue || !dataoutPtr || empty_queue(queue)) return 0;
    memcpy(dataoutPtr,queue->head->dataptr,queue->head->size);
    NODE* aux = queue->head;
    queue->head = queue->head->next;
    free(aux->dataptr);
    free(aux);
    if(queue->head == NULL) queue->rear = NULL;
    queue->count--;
    return 1;
}
int queue_front (QUEUE*queue,void*dataoutPtr)
{
    if(!queue || !dataoutPtr || empty_queue(queue)) return 0;
    memcpy(dataoutPtr,queue->head->dataptr,queue->head->size);
    return 1;
}
int queue_rear (QUEUE*queue,void*dataoutPtr)
{
    if(!queue || !dataoutPtr || empty_queue(queue)) return 0;
    memcpy(dataoutPtr,queue->rear->dataptr,queue->rear->size);
    return 1;
}
void destroy_queue(QUEUE*queue)
{
    NODE* aux;
    if(!queue) return;
    while(queue->head != NULL)
    {
        aux = queue->head;
        queue->head = queue->head->next;
        free(aux->dataptr);
        free(aux);
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
    if(!queue) return 1;
    return queue->count == 0;
}