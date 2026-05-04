#include <stdlib.h>
#include <stdio.h>
#include "stackadt.h"
#define STACK_OK 1
#define STACK_ERR 0
#define STACK_ERR_NULL -1

typedef struct stNode {
    int data;
    struct stNode *prox;
} NODE;

typedef struct stack {
    int count;
    NODE *head;
}STACK;

STACK* create_stack()
{
    STACK *stack = (STACK*)malloc(sizeof(STACK));
    if (stack == NULL) 
    {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    stack->count = 0;
    stack->head = NULL;
    return stack;
}
int push_stack(STACK* stack,int valor)
{
    if(stack == NULL) return STACK_ERR_NULL;
    NODE* node = (NODE*)malloc(sizeof(NODE));
    if (node == NULL) return STACK_ERR_NULL;
    node->data = valor;
    node->prox = stack->head;
    stack->head = node;
    stack->count++;
    return STACK_OK;
}
int pop_stack(STACK* stack, int *out)
{
    if(stack == NULL || out == NULL) return STACK_ERR_NULL;
    if(empty_stack(stack)) return STACK_ERR;
    NODE* aux = stack->head;
    *out = aux->data;
    stack->head = stack->head->prox;
    free(aux);
    stack->count--;
    return STACK_OK;
}
int peek(STACK* stack, int *out)
{
    if(stack == NULL || out == NULL) return STACK_ERR_NULL;
    if(empty_stack(stack))
    {
        return STACK_ERR;
    }
    *out = stack->head->data;
    return STACK_OK;
}
int empty_stack(STACK*stack)
{
    return stack->count == 0;
}
int stack_count(STACK*stack)
{
    return stack->count;
}
int destroy_stack(STACK*stack)
{
    if (stack == NULL) return STACK_ERR_NULL;
    NODE *temp;
    while(!empty_stack(stack))
    {
        temp = stack->head;
        stack->head = stack->head->prox;
        free(temp);
    }
    free(stack);
    return STACK_OK;
}