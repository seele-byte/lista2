typedef struct Queue QUEUE;
QUEUE* create_queue();
int enqueue(QUEUE*queue,void* dataptr,size_t size);
int dequeue(QUEUE*queue,void*dataoutptr);
int queue_front (QUEUE*queue,void*dataoutptr);
int queue_rear (QUEUE*queue,void*dataoutptr);
void destroy_queue(QUEUE*queue);
int queue_size(QUEUE*queue);
int empty_queue(QUEUE*queue);