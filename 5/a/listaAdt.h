typedef struct stlista LISTA;
LISTA* criar_lista(void);
int inserir_elemento(LISTA*,int);
int remover_elemento(LISTA*,int);
int buscar_elemento(LISTA*,int);
void destruir_lista(LISTA*);
int lista_tamanho(LISTA*);
int lista_vazia(LISTA*);
int lista_cheia(LISTA*);