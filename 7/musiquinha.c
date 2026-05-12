#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listADT.h"

typedef struct{
    char titulo[100];
    char artista[100];
    int ano;
}MUSICA;

int compare_musica(void *a,void *b){

    MUSICA* m1 = (MUSICA*)a;
    MUSICA* m2 = (MUSICA*)b;

    return strcmp(m1->titulo, m2->titulo); // 0 igual, <0 1 menor q 2, >0 1 maior q 2
}

void print_musica(void *a){

    MUSICA* m = (MUSICA*)a;
    
    printf("Titulo: %s\n", m->titulo);
    printf("Artista: %s\n", m->artista);
    printf("Ano: %d\n", m->ano);
}

int main(){

    LISTA* lista = criar_lista(compare_musica);

    FILE* arq = fopen("musicas.txt", "r");

    if(arq == NULL){
        printf("Erro ao abrir arquivo.\n");
        return 1;
    }

    MUSICA musica;

 while(fgets(musica.titulo, 100, arq)){

    musica.titulo[strcspn(musica.titulo, "\n")] = '\0';

    fgets(musica.artista, 100, arq);
    musica.artista[strcspn(musica.artista, "\n")] = '\0';

    fscanf(arq, "%d", &musica.ano);

    fgetc(arq);

    inserir_elemento(lista, &musica, sizeof(MUSICA));
}

    fclose(arq);

    printf("\nFORWARD:\n\n");
    forward(lista, print_musica);

    printf("\nBACKWARD:\n\n");
    backward(lista, print_musica);

    destruir_lista(lista);

    return 0;
}