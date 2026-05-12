#define TAMANHO 10
#define STACK_OK 1
#define STACK_ERR 0
#define STACK_ERR_NULL -1
typedef struct stack STACK;
//cria uma estrutura stack
STACK* create_stack();
//adiciona um elemento a pilha
int push_stack(STACK* stack,int valor);
//remove e retorna o elemento no topo da pilha
int pop_stack(STACK* stack,int *out);
//retorna o elemento no topo da pilha
int peek(STACK* stack, int *out);
//retorna 1 caso a pilha esteja vazia, 0 caso contrário
int empty_stack(STACK*stack);
//retorna 1 caso a pilha esteja cheia, 0 caso contrário
int full_stack(STACK*stack);
//retorna o tamanho da pilha
int stack_count(STACK*stack);
//destroi a pilha
int destroy_stack(STACK*stack);


