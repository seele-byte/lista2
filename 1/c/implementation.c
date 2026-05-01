#include <stdio.h>
#include <stdlib.h>
#include "stackadt.h"

int main ()
{
    void* dataoutptr = malloc(sizeof(int));
    int contador,valor;
    STACK* stack = create_stack();
    printf("Digite o número de inteiros que a sequência terá\n");
    scanf("%d",&contador);
    printf("Digite a sequência: \n");
    while(contador > 0)
    {
        scanf("%d",&valor);
        push_stack(stack,&valor,sizeof(int));
        contador--;
    }
    printf("\n");
    while(!empty_stack(stack))
    {
        pop_stack(stack,dataoutptr);
        printf(" %d ",*(int*)dataoutptr);
    }
    destroy_stack(stack);
    free(dataoutptr);
}