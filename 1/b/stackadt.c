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
    if(stack == NULL){
        printf("\nNão foi possível adicionar um elemento à pilha\n");
        return;
    }
    NODE* node = (NODE*)malloc(sizeof(NODE));
    if (node == NULL){
        printf("\nErro de Alocação de memória\n");
        return;
    }
    node->data = valor;
    node->prox = stack->head;
    stack->head = node;
    stack->count++;
    return;
}
void pop_stack(STACK* stack, int *out)
{
    if(stack == NULL || out == NULL){
        printf("\nNão Foi possível remover um elemento no topo da pilha\n");
        return;
    }
    if(empty_stack(stack)){
        printf("\nNão é possível remover um elemento de uma pilha vazia!\n");
        return;
    }
    NODE* aux = stack->head;
    *out = aux->data;
    stack->head = stack->head->prox;
    free(aux);
    stack->count--;
    return;
}
void peek(STACK* stack, int *out)
{
    if(stack == NULL || out == NULL){
        printf("\nNão foi possível verificar o elemento no topo da pilha\n");
        return;
    }
    if(empty_stack(stack))
    {
        printf("\nA pilha está vazia!\n");
    }
    *out = stack->head->data;
    return;
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
    return;
}