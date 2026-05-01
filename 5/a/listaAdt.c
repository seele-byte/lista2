#include <stdlib.h>
#include <stdio.h>
#include "listaAdt.h"

typedef struct stnode
{
    int dado;
    struct stnode *next;
} NODE;

typedef struct stLista
{
    NODE *head;
    int count;
} LISTA;

static NODE* buscapos(LISTA *lista, int elemento);

LISTA* criar_lista(void)
{
    LISTA *lista = (LISTA*) malloc(sizeof(LISTA));

    if (!lista) return NULL;

    lista->head = NULL;
    lista->count = 0;

    return lista;
}

int inserir_elemento(LISTA *lista, int elemento)
{
    if (!lista) return 0;

    NODE *novo = (NODE*) malloc(sizeof(NODE));
    if (!novo) return 0;

    novo->dado = elemento;
    novo->next = NULL;

    NODE *pPre = buscapos(lista, elemento);

    if (pPre == NULL)
    {
        novo->next = lista->head;
        lista->head = novo;
    }
    else
    {
        novo->next = pPre->next;
        pPre->next = novo;
    }

    lista->count++;
    return 1;
}

int remover_elemento(LISTA *lista, int elemento)
{
    if (!lista || !lista->head) return 0;

    NODE *remover;

    if (lista->head->dado == elemento)
    {
        remover = lista->head;
        lista->head = lista->head->next;
        free(remover);
        lista->count--;
        return 1;
    }

    NODE *pPre = buscapos(lista, elemento);

    if (pPre && pPre->next && pPre->next->dado == elemento)
    {
        remover = pPre->next;
        pPre->next = remover->next;
        free(remover);
        lista->count--;
        return 1;
    }

    return 0;
}

int buscar_elemento(LISTA *lista, int elemento)
{
    if (!lista || !lista->head) return 0;

    if (lista->head->dado == elemento)
        return 1;

    NODE *pPre = buscapos(lista, elemento);

    if (pPre && pPre->next && pPre->next->dado == elemento)
        return 1;

    return 0;
}

void destruir_lista(LISTA *lista)
{
    if (!lista) return;

    NODE *temp = lista->head;

    while (temp)
    {
        NODE *aux = temp;
        temp = temp->next;
        free(aux);
    }

    free(lista);
}

int lista_tamanho(LISTA *lista)
{
    if (!lista) return 0;
    return lista->count;
}

int lista_vazia(LISTA *lista)
{
    if (!lista) return 1;
    return lista->count == 0;
}

static NODE* buscapos(LISTA *lista, int elemento)
{
    NODE *pPre = NULL;
    NODE *pLoc = lista->head;

    while (pLoc && pLoc->dado < elemento)
    {
        pPre = pLoc;
        pLoc = pLoc->next;
    }

    return pPre;
}