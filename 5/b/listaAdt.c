#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct stNode {
    void* dataptr;
    size_t size;
    struct stNode*next;
}NODE;
typedef struct stlista{
    NODE* head;
    int count;
    int (*compare) (void* argu1, void* argu2);
} LISTA;

LISTA* criar_lista(int (*compare_function)(void*argu1,void*argu2)){
    LISTA* lista = (LISTA*)malloc(sizeof(LISTA));
    if(lista)
    {
        lista->head = NULL;
        lista->count = 0;
        lista->compare = compare_function;
    }
    return lista;
}
static int _search(LISTA*, NODE**, NODE**, void*);
static int _insert(LISTA*, NODE*, void*, size_t);
static void _delete(LISTA*, NODE*, NODE*);
int inserir_elemento(LISTA* lista,void*datainPtr,size_t size){
    int success,found;
    NODE *pPre,*pLoc;
    found = _search(lista,&pPre,&pLoc,datainPtr);
    if(found) return 1;
    success = _insert(lista,pPre,datainPtr,size);
    return success;
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
    if(!lista) return;
    NODE *deletePtr;
        while(lista->count > 0){
            free(lista->head->dataptr);
            deletePtr = lista->head;
            lista->head = lista->head->next;
            lista->count--;
        }
    free(lista);
}
static int _search(LISTA* lista,NODE** pPre,NODE** pLoc,void* datainPtr){
    #define COMPARE lista->compare((*pLoc)->dataptr, datainPtr)
    int result;
    *pPre = NULL;
    *pLoc = lista->head;
    if(lista->count == 0) return 0;
    while(*pLoc != NULL && ((result = COMPARE) > 0))
    {
        *pPre = *pLoc;
        *pLoc = (*pLoc)->next;
    }
    if(result == 0){
        return 1;
    }
    return 0;

}
static int _insert(LISTA* lista,NODE *pPre,void*datainPtr,size_t size){
    NODE* pNew;
    pNew = NULL; // <------------------------------
    if(!(pNew = (NODE*)malloc(sizeof(NODE)))) goto erro;
    pNew->dataptr = malloc(size);
    if(!pNew->dataptr) goto erro;
    memcpy(pNew->dataptr,datainPtr,size);
    pNew->size = size;
    pNew->next = NULL;
    if(!pPre)
    {
        pNew->next = lista->head;
        lista->head = pNew;
    }
    else {
        pNew->next = pPre->next;
        pPre->next = pNew;
    }
    lista->count++;
    return 1;
    erro:
        if(pNew) {
            if(pNew->dataptr) free(pNew->dataptr);
            free(pNew);
        }
    return 0;
}
int empty_list(LISTA*lista){
    return(lista->count == 0);
}
int full_list(LISTA* lista){
    NODE* temp = (NODE*)malloc(sizeof(NODE));
    if(temp){
        free(temp);
        return 0;
    }
    return 1;
}
int list_count (LISTA* lista){
    return lista->count;
}