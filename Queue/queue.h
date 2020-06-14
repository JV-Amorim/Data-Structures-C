#ifndef CHAINED_QUEUE_H
#define CHAINED_QUEUE_H

typedef struct _Queue Queue;
struct _Queue
{
    int capacity;
    int head;
    int tail;
    void** elements;
};

Queue* QueueFactory(int capacity);
int IsTheQueueEmpty(Queue* queue);
int IsTheQueueFull(Queue* queue);
int GetTheHeadValueRelativeToTheCapacity(Queue* queue);
int GetTheTailValueRelativeToTheCapacity(Queue* queue);
void Enqueue(Queue* queue, void* newElement);
void* Dequeue(Queue* queue);
void DesallocateQueue(Queue* queue, void (*ElementDesallocationFunction)());

#endif