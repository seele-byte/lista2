#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackadt.h"

typedef struct stNode {
    void *dataptr;
    size_t size;
    struct stNode *prox;
} NODE;

typedef struct stack {
    int count;
    NODE *head;
}STACK;

STACK* create_stack()
{
    STACK* stack = (STACK*)malloc(sizeof(STACK));
    if(!stack)
    {
        printf("Erro de alocação de memória!\n");
        return NULL;
    }
    stack->count = 0;
    stack->head = NULL;
    return stack;
}
void push_stack(STACK* stack,void *datainPtr,size_t size)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    if(!node)
    {
        printf("ERRO DE ALOCAÇÃO DE MEMÓRIA\n");
        return;
    }
    node->dataptr = malloc(size);
    if (!node->dataptr)
    {
        printf("ERRO DE ALOCAÇÃO DE MEMÓRIA\n");
        free(node);
        return;
    }
    memcpy(node->dataptr,datainPtr,size);
    node->size = size;
    node->prox = stack->head;
    stack->head = node;
    stack->count++;
}
void pop_stack(STACK* stack,void* dataoutPtr)
{
    if(empty_stack(stack))
    {
        printf("EMPTY STACK!\n");
        return;
    }
    NODE* aux = stack->head;
    stack->head = stack->head->prox;
    memcpy(dataoutPtr,aux->dataptr,aux->size);
    free(aux->dataptr);
    free(aux);
    stack->count--;
}
void* peek(STACK* stack)
{
    if(empty_stack(stack)) return NULL;
    return stack->head->dataptr;
}
int empty_stack(STACK*stack)
{
    return stack->head == NULL;
}
int stack_count(STACK*stack)
{
    return stack->count;
}
void destroy_stack(STACK*stack)
{
    NODE* temp;
    while(!empty_stack(stack))
    {
        temp = stack->head;
        stack->head = stack->head->prox;
        free(temp->dataptr);
        free(temp);
    }
    free(stack);
}