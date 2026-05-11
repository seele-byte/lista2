typedef struct stlista LISTA;
LISTA* criar_lista(int (*compare_function)(void*,void*));
int inserir_elemento(LISTA*,void*);
int remover_elemento(LISTA*,void*);
void buscar_elemento(LISTA*,void*);
void destruir_lista(LISTA*);
int lista_tamanho(LISTA*);