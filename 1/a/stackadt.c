#include <stdlib.h>
#include <stdio.h>
#include "stackadt.h"
#define TAMANHO 10
#define STACK_OK 1
#define STACK_ERR 0
#define STACK_ERR_NULL -1

typedef struct stack {
    int top;
    int vetor[TAMANHO];
}STACK;


STACK* create_stack()
{
    STACK* stack = (STACK*) malloc(sizeof(STACK));
    if (stack == NULL)
    {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
    stack->top = -1;
    return stack;
}

int push_stack(STACK* stack,int valor) 
{
    if (!stack) return STACK_ERR_NULL;
    if(full_stack(stack)) return STACK_ERR;
    stack->vetor[++stack->top] = valor;
    return STACK_OK;
}

int pop_stack(STACK* stack, int *out)
{
    if(!stack || !out) return STACK_ERR_NULL;
    if(empty_stack(stack))  return STACK_ERR;
    *out = stack->vetor[stack->top--];
    return STACK_OK;
}
int peek(STACK* stack, int *out)
{
    if (!stack || !out) return STACK_ERR_NULL;
    if (empty_stack(stack)) return STACK_ERR;
    *out = stack->vetor[stack->top];
    return STACK_OK;
}
int empty_stack(STACK*stack)
{
    return stack->top == -1;
}
int full_stack(STACK*stack)
{
    return stack->top == TAMANHO-1;
}
int stack_count(STACK*stack)
{
    return stack->top+1;
}
int destroy_stack(STACK*stack)
{
    free(stack);
    return STACK_OK;
}