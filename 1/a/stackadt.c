#include <stdlib.h>
#include <stdio.h>
#include "stackadt.h"

#define TAMANHO 7

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
    if (!stack){
        printf("Erro de Alocação de memória\n");
        return;
    }
    if(full_stack(stack)){
        printf("Pilha Cheia!\n");
        return;
    }
    stack->vetor[++stack->top] = valor;
}

void pop_stack(STACK* stack, int *out)
{
    if(!stack || !out){
        printf("Não foi possível retirar o elemento da pilha\n");
        return;
    }
    if(empty_stack(stack)){
        printf("Não é possivel remover o elemento de uma pilha vazia!\n");
        return;
    }
    *out = stack->vetor[stack->top--];
    return;
}
void peek(STACK* stack, int *out)
{
    if (!stack || !out){
        printf("Não foi possível retirar o elemento da pilha\n");
        return;
    }
    if (empty_stack(stack)){
        printf("A pilha está vazia!\n");
        return;
    }
    *out = stack->vetor[stack->top];
    return;
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