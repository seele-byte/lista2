#include <stdlib.h>
#include <stdio.h>

typedef struct stNode {
    int coeficiente;
    int grau;
    struct stNode *next;
}NODE;
/* Declaração de funções */
NODE* preencher_polinomio();
void adicionar_elemento(NODE** pHead,int grau,int coeficiente);
int buscapos(NODE** pHead,NODE** pPre,NODE** pLoc,int grau);
void multiplicar_polinomio(NODE* head_polinomio1,NODE* head_polinomio2);
void mostrar_polinomio(NODE* head);
void destruir_polinomio(NODE* head);

int main (){
    printf("Polinômio 1:\n");
    NODE* polinomio_1 = preencher_polinomio();
    printf("Polinômio 2:\n");
    NODE* polinomio_2 = preencher_polinomio();
    printf("\n\n\n O polinômio 1 é: ");
    mostrar_polinomio(polinomio_1);
    printf("\n\n\n O polinômio 2 é: ");
    mostrar_polinomio(polinomio_2);
    multiplicar_polinomio(polinomio_1,polinomio_2);
    destruir_polinomio(polinomio_1);
    destruir_polinomio(polinomio_2);
}
NODE* preencher_polinomio(){
    int op = 0,grau,coeficiente;
    NODE* head = NULL;
    while(op != -1){
        printf("Preencha o termo a ser adicionado ao polinomio: \n");
        printf("Grau: ");
        scanf("%d",&grau);
        printf("\n");
        printf("Coeficiente: ");
        scanf("%d",&coeficiente);
        adicionar_elemento(&head,grau,coeficiente);
        printf("Digite -1 caso queira terminar de adicionar elementos ");
        scanf("%d",&op);
    }
    return head;
}
void adicionar_elemento(NODE** pHead,int grau,int coeficiente){
    NODE *pPre,*pLoc;
    int result = buscapos(pHead,&pPre,&pLoc,grau);
    if(result == -1){
        pLoc->coeficiente += coeficiente;
        return;
    }
    NODE* node = (NODE*)malloc(sizeof(NODE));
    node->grau = grau;
    node->coeficiente = coeficiente;
    if(result == 0){
        node->next = *pHead;
        *pHead = node;
        return;
    }
    node->next = pLoc;
    pPre->next = node;
}
/*
    buscapos retorna um status dizendo oque deve ser feito para adicionar o polinômio
    0 caso o elemento deva ser adicionado no inicio da lista
    1 caso o elemento deva ser adicionado no meio/final da lista
    -1 caso o elemento não precise ser adicionado na lista (já existe um termpo com o mesmo grau)
*/
int buscapos(NODE** pHead,NODE** pPre,NODE** pLoc,int grau){

    if(!(*pHead) || (*pHead)->grau < grau) return 0;

    *pPre = NULL;
    *pLoc = *pHead;

    while(*pLoc && (*pLoc)->grau > grau){
        *pPre = *pLoc;
        *pLoc = (*pLoc)->next;
    }

    if(!(*pLoc) || (*pLoc)->grau != grau){
        return 1;
    }
    return -1;
}
void multiplicar_polinomio(NODE* head_polinomio1,NODE* head_polinomio2){
    NODE *head_polinomio_produto = NULL,*temp1 = head_polinomio1,*temp2 = head_polinomio2;
    int grau,coeficiente;
    while(temp1){
        while(temp2){
            grau = temp1->grau + temp2->grau;
            coeficiente = temp1->coeficiente * temp2->coeficiente;
            adicionar_elemento(&head_polinomio_produto,grau,coeficiente);
            temp2 = temp2->next;
        }
        temp2 = head_polinomio2;
        temp1 = temp1->next;
    }
    printf("\n\n\n o Resultado da multiplicação é: ");
    mostrar_polinomio(head_polinomio_produto);
    destruir_polinomio(head_polinomio_produto);
}
void mostrar_polinomio(NODE* head){
    if(!head) return;
    printf("(%d X ^ %d) ",head->coeficiente,head->grau);
    head = head->next;
    while(head){
        printf(" + (%d X ^ %d) ",head->coeficiente,head->grau);
        head = head->next;
    }
}
void destruir_polinomio(NODE* head){
    NODE* aux;
    while(head){
        aux = head;
        head = head->next;
        free(aux);
    }
}