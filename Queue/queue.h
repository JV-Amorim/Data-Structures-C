#ifndef QUEUE_H
#define QUEUE_H

typedef struct _Node Node;
struct _Node
{
    Node* next;
    void* element;
};

typedef struct _Queue Queue;
struct _Queue
{
    Node* head;
    Node* tail;
    int length;
};

Queue* QueueFactory();
int IsTheQueueEmpty(Queue* queue);
void Enqueue(Queue* queue, void* newElement);
void* Dequeue(Queue* queue);
void DesallocateQueue(Queue* queue, void (*ElementDesallocationFunction)());
void ShowQueueStatus(Queue* queue);

void ReadDataFromAllElements(Queue* queue, void (*ElementReadFunction)());

#endif