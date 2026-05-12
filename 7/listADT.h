#include <stdlib.h>
typedef struct stlista LISTA;
LISTA* criar_lista(int (*compare_function)(void*,void*));
int inserir_elemento(LISTA*,void*, size_t);
int remover_elemento(LISTA*,void*);
void buscar_elemento(LISTA*,void*);
void destruir_lista(LISTA*);
int lista_tamanho(LISTA*);
void forward(LISTA*, void (*print)(void*));
void backward(LISTA*, void (*print)(void*));