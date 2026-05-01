#include <stdio.h>
#include <stdlib.h>
#include "stackadt.h"

int main ()
{
    int valor;
    STACK* stack = create_stack();
    while(!full_stack(stack))
    {
        scanf("%d",&valor);
        push_stack(stack,valor);
    }
    printf("\n");
    while(!empty_stack(stack))
    {
        printf(" %d ",pop_stack(stack));
    }
}