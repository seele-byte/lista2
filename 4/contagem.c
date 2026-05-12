#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "../3/c/queueadt.h"

typedef struct stLista 
{
    char letra_inicial;
    struct stLista *next;
    void *fila;
}NODE_PALAVRAS;
NODE_PALAVRAS* head_palavras = NULL;
void adicionar_palavra (char* palavra);
int main ()
{
    int check = 0,mais_frequente = 0;
    char palavra [46],caractere_mais_repetido;
    FILE *arq;
    int count = 0,tamanho_maior_fila = 0;
    arq = fopen("letra.txt","r");
    if(!arq)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }
    while((fscanf(arq,"%s",palavra)) != EOF)
    {
        adicionar_palavra(palavra);
        count++;
    }
    while(head_palavras)
    {
        NODE_PALAVRAS* aux = head_palavras;
        head_palavras = head_palavras->next;
        int tamanho = queue_size(aux->fila);
        if(tamanho > tamanho_maior_fila)
        {
            tamanho_maior_fila = tamanho;
            caractere_mais_repetido = aux->letra_inicial;
        }
        printf(" %d palavras começam com o caractere %c\n",tamanho,aux->letra_inicial);
        destroy_queue(aux->fila);
        free(aux);
    }
    printf("\nO caractere que aparece com maior frequência é %c\n",caractere_mais_repetido);
    fclose(arq);
}
void adicionar_palavra(char *palavra)
{
    *palavra = tolower((unsigned char)*palavra);

    if (!head_palavras)
    {
        NODE_PALAVRAS *node = malloc(sizeof(NODE_PALAVRAS));
        node->letra_inicial = *palavra;
        node->fila = create_queue();
        node->next = NULL;
        enqueue(node->fila, palavra, strlen(palavra) + 1);
        head_palavras = node;
        return;
    }

    NODE_PALAVRAS *temp = head_palavras;

    while (temp)
    {
        if (temp->letra_inicial == *palavra)
        {
            enqueue(temp->fila, palavra, strlen(palavra) + 1);
            return;
        }

        if (temp->next == NULL)
            break;

        temp = temp->next;
    }

    NODE_PALAVRAS *node = malloc(sizeof(NODE_PALAVRAS));
    node->letra_inicial = *palavra;
    node->fila = create_queue();
    node->next = NULL;
    enqueue(node->fila, palavra, strlen(palavra) + 1);
    temp->next = node;
}
