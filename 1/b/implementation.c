#include <stdio.h>
#include <stdlib.h>
#include "stackadt.h"

int main ()
{
    int valor,contador;
    int *p = &valor;
    STACK* stack = create_stack();
    printf("Digite o numero de inteiros que a sequencia tera\n");
    scanf("%d",&contador);
    printf("Digite a sequencia: \n");
    while(contador > 0)
    {
        scanf("%d",&valor);
        push_stack(stack, valor);
        contador--;
    }
    printf("\n");
    while(!empty_stack(stack))
    {
        pop_stack(stack, &valor);
        printf(" %d ", valor);
    }
}