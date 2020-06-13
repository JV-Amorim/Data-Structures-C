#ifndef CHAINED_QUEUE_H
#define CHAINED_QUEUE_H

typedef struct _Node Node;
struct _Node
{
    Node* next;
    void* element;
};

typedef struct _ChainedQueue ChainedQueue;
struct _ChainedQueue
{
    Node* head;
    Node* tail;
    int length;
};

ChainedQueue* ChainedQueueFactory();
int IsTheChainedQueueEmpty(ChainedQueue* queue);
void Enqueue(ChainedQueue* queue, void* newElement);
void* Dequeue(ChainedQueue* queue);
void DesallocateChainedQueue(ChainedQueue* queue, void (*ElementDesallocationFunction)());
void ShowChainedQueueStatus(ChainedQueue* queue);

void ReadDataFromAllElements(ChainedQueue* queue, void (*ElementReadFunction)());

#endif