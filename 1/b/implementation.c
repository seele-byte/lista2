#include <stdio.h>
#include <stdlib.h>
#include "stackadt.h"

int main ()
{
    int valor,contador;
    STACK* stack = create_stack();
    printf("Digite o número de inteiros que a sequência terá\n");
    scanf("%d",&contador);
    printf("Digite a sequência: \n");
    while(contador > 0)
    {
        scanf("%d",&valor);
        push_stack(stack,valor);
        contador--;
    }
    printf("\n");
    while(!empty_stack(stack))
    {
        printf(" %d ",pop_stack(stack));
    }
}