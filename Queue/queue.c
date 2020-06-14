#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

Queue* QueueFactory(int capacity)
{
    Queue* newQueue = malloc(sizeof(Queue));
    newQueue->elements = malloc(sizeof(void*) * capacity);
    newQueue->capacity = capacity;
    newQueue->head = 0;
    newQueue->tail = -1;
    return newQueue;
}

int IsTheQueueEmpty(Queue* queue)
{
    if (queue == NULL)
        return 1;
    if (queue->tail < queue->head)
        return 1;
    return 0;
}

int IsTheQueueFull(Queue* queue)
{
    if (queue->tail + 1 >= queue->capacity + queue->head)
        return 1;
    return 0;
}

int GetTheHeadValueRelativeToTheCapacity(Queue* queue)
{
    return queue->head % queue->capacity;
}

int GetTheTailValueRelativeToTheCapacity(Queue* queue)
{
    return queue->tail % queue->capacity;
}

void Enqueue(Queue* queue, void* newElement)
{
    int tailRelativeValue;

    if (queue == NULL)
    {
        printf("The queue is null.\n");
        return;
    }
    if (IsTheQueueFull(queue) == 1)
    {
        printf("The queue is full.\n");
        return;
    }

    queue->tail += 1;

    tailRelativeValue = GetTheTailValueRelativeToTheCapacity(queue);

    queue->elements[tailRelativeValue] = newElement;
}

void* Dequeue(Queue* queue)
{
    int headRelativeValue;
    void* elementToReturn;

    if (IsTheQueueEmpty(queue) == 1)
    {
        printf("The queue is empty or null.\n");
        return NULL;
    }

    headRelativeValue = GetTheHeadValueRelativeToTheCapacity(queue);

    elementToReturn = queue->elements[headRelativeValue];
    queue->head++;

    return elementToReturn;
}

void DesallocateQueue(Queue* queue, void (*ElementDesallocationFunction)())
{
    int headRelativeValue;

    if (queue == NULL)
        return;

    for (queue->head = queue->head ; queue->head <= queue->tail; queue->head++)
    {
        headRelativeValue = GetTheHeadValueRelativeToTheCapacity(queue);
        ElementDesallocationFunction(queue->elements[headRelativeValue]);
    }

    free(queue->elements);
    free(queue);
}