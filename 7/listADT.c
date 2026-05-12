#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct stNode {
    void* dataptr;
    size_t size;
    struct stNode*next;
    struct stNode*prev;
}NODE;
typedef struct stlista{
    NODE* head;
    NODE* tail;
    int count;
    int (*compare) (void* argu1, void* argu2);
} LISTA;

LISTA* criar_lista(int (*compare_function)(void*argu1,void*argu2)){
    LISTA* lista = (LISTA*)malloc(sizeof(LISTA));
    if(lista)
    {
        lista->head = NULL;
        lista->tail = NULL;
        lista->count = 0;
        lista->compare = compare_function;
    }
    return lista;
}
static int _search(LISTA*, NODE**, NODE**, void*);
static int _insert(LISTA*, NODE*, void*, size_t);
static void _delete(LISTA*, NODE*, NODE*);
int inserir_elemento(LISTA* lista,void*datainPtr,size_t size){
    int status,found;
    NODE *pPre,*pLoc;
    found = _search(lista,&pPre,&pLoc,datainPtr);
    if(found) return 1;
    status = _insert(lista,pPre,datainPtr,size);
    return status;
}
int remover_elemento(LISTA* lista,void*dataptr)
{
    int found;
    NODE *pPre,*pLoc;
    found = _search(lista,&pPre,&pLoc,dataptr);
    if(found) _delete(lista,pPre,pLoc);
    return found;
}
static void _delete(LISTA*lista,NODE*pPre,NODE*pLoc)
{
    if(!pPre){
        lista->head = pLoc->next;
    }
    else{
        pPre->next = pLoc->next;
    }
    lista->count--;
    free(pLoc->dataptr);
    free(pLoc);
}
int buscar_elemento(LISTA* lista,void*key, void**pdataoutPtr)
{
    int found;
    NODE *pPre,*pLoc;
    found = _search(lista,&pPre,&pLoc,key);
    if(found){
        *pdataoutPtr = pLoc->dataptr;
    }
    else{
        *pdataoutPtr = NULL;
    }
    return found;
}
void destruir_lista(LISTA *lista){
    NODE *deletePtr;
    while(lista){
        while(lista->count > 0){
            free(lista->head->dataptr);
            deletePtr = lista->head;
            lista->head = lista->head->next;
            lista->count--;
        }
    }
    free(lista);
}
static int _search(LISTA* lista,NODE** pPre,NODE** pLoc,void* datainPtr){

  int result;

    *pPre = NULL;
    *pLoc = lista->head;

    if(lista->head == NULL)
        return 0;

    do{

        result = lista->compare((*pLoc)->dataptr, datainPtr);

        if(result == 0){
            return 1;
        }

        if(result > 0){
            break;
        }

        *pPre = *pLoc;
        *pLoc = (*pLoc)->next;

    }while(*pLoc != lista->head);

    if(*pPre == NULL)
        *pPre = lista->head->prev;

    return 0;
}
static int _insert(LISTA* lista,NODE *pPre,void*datainPtr,size_t size){
    NODE* pNew;
    NODE* pLoc;
    pNew = NULL;
    if(!(pNew = (NODE*)malloc(sizeof(NODE)))) goto erro;
    pNew->dataptr = NULL;
    pNew->dataptr = malloc(size);
    if(!pNew->dataptr) goto erro;
    memcpy(pNew->dataptr,datainPtr,size);
    pNew->size = size;
    if(lista->head == NULL){
        pNew->next = pNew;
        pNew->prev = pNew;
        lista->head = pNew;
    } else{
        if(pPre == lista->head->prev && lista->compare(datainPtr, lista->head->dataptr) < 0){
            pLoc = lista->head;
            pNew->next = pLoc;
            pNew->prev = pLoc->prev;

            pLoc->prev->next = pNew;
            pLoc->prev = pNew;

            lista->head = pNew;
        }else{
            pLoc = pPre->next;
            
            pNew->next = pLoc;
            pNew->prev = pPre;

            pPre->next->prev = pNew;
            pPre->next = pNew;
        }

    }

    lista->count++;
    return 1;
    erro:
    if(pNew) if(pNew->dataptr) free(pNew->dataptr);
    free(pNew);
    return 0;
}
int empty_list(LISTA*lista){
    return(lista->count == 0);
}
int full_list(LISTA* lista){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    if(temp){
        free(temp);
        return 1;
    }
    return 0;
}
int list_count (LISTA* lista){
    return lista->count;
}