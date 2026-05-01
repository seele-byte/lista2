#include <stdlib.h>
#include <stdio.h>
#include "stackadt.h"

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
void push_stack(STACK* stack,int valor)
{
    NODE* node = (NODE*)malloc(sizeof(NODE));
    if (node == NULL)
    {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    node->data = valor;
    node->prox = stack->head;
    stack->head = node;
    stack->count++;
}
int pop_stack(STACK* stack)
{
    if(empty_stack(stack))
    {
        printf("EMPTY STACK\n");
        return 0;
    }
    NODE* aux = stack->head;
    int aux_val = aux->data;
    stack->head = stack->head->prox;
    free(aux);
    stack->count--;
    return aux_val;
}
int peek(STACK* stack)
{
    if(empty_stack(stack))
    {
        printf("EMPTY STACK\n");
        return 0;
    }
    return stack->head->data;
}
int empty_stack(STACK*stack)
{
    return stack->count == 0;
}
int stack_count(STACK*stack)
{
    return stack->count;
}
void destroy_stack(STACK*stack)
{
    if (stack == NULL) return;
    NODE *temp;
    while(!empty_stack(stack))
    {
        temp = stack->head;
        stack->head = stack->head->prox;
        free(temp);
    }
    free(stack);
}