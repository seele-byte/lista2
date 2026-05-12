#include <stdlib.h>
#include <stdio.h>
#include "queueadt.h"

int main ()
{
    int op = 1,data;
    void*dataout = malloc(sizeof(int));
    QUEUE* fila = create_queue();
    do
    {
        printf("============================================\n");
        printf("Digite a opção que deseja realizar na fila\n");
        printf(" 1 - enqueue\n"); 
        printf(" 2 - dequeue\n"); 
        printf(" 3 - queue front\n"); 
        printf(" 4 - queue rear\n"); 
        printf(" 5 - queue size\n"); 
        printf(" 6 - destroy queue\n"); 
        scanf("%d",&op);
        switch (op)
        {
            case 1:
                printf("Digite o valor que deseja adicionar na fila: ");
                scanf("%d",&data);
                if(enqueue(fila,&data,sizeof(int))) printf("Elemento adicionado\n");
                break;
            case 2:
                if(dequeue(fila,dataout)) printf("elemento %d removido da fila\n",*(int*)dataout);
                break;
            case 3:
                if(queue_front(fila,dataout)) printf("o elemendo %d está na frente da fila\n",*(int*)dataout);
                break;
            case 4:
                if(queue_rear(fila,dataout)) printf("o elemento %d está no final da fila\n",*(int*)dataout);
                break;
            case 5:
                printf("O tamanho da fila é %d \n",queue_size(fila));
                break;
        }
        printf("============================================\n");
    }while(op != 6);
    destroy_queue(fila);
    free(dataout);
    printf("Programa encerrado\n");
}