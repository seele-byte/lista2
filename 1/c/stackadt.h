typedef struct stack STACK;
//cria uma estrutura stack
STACK* create_stack();
//adiciona um elemento a pilha
void push_stack(STACK* stack,void *datainPtr,size_t size);
//remove e retorna o elemento no topo da pilha para dataoutPtr
void pop_stack(STACK* stack,void *dataoutPtr);
//retorna um ponteiro pra void no primeiro elemento da pilha
void* peek(STACK* stack);
//retorna 1 caso a pilha esteja vazia, 0 caso contrário
int empty_stack(STACK*stack);
//retorna o tamanho da pilha
int stack_count(STACK*stack);
//destroi a pilha
void destroy_stack(STACK*stack);
