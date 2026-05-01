#include <stdlib.h>
#include <stdio.h>
#include "stackadt.h"
#define TAMANHO 10

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

void push_stack(STACK* stack,int valor) 
{
    if (stack == NULL) return;
    else if(full_stack(stack))
    {
        printf("FULL STACK!\n");
        return;
    }
    stack->vetor[++stack->top] = valor;
}

int pop_stack(STACK* stack)
{
    if(empty_stack(stack))
    {
        printf("EMPTY STACK!\n");
        return 0;
    }
    return stack->vetor[stack->top--];
}
int peek(STACK* stack)
{
    if (empty_stack(stack))
    {
        printf("EMPTY STACK!");
        exit(1);
    }
    return stack->vetor[stack->top];
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
void destroy_stack(STACK*stack)
{
    free(stack);
}