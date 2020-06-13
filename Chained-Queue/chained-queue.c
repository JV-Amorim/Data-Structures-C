#include <stdio.h>
#include <stdlib.h>
#include "chained-queue.h"

ChainedQueue* ChainedQueueFactory()
{
    ChainedQueue* newQueue = malloc(sizeof(ChainedQueue));
    newQueue->head = NULL;
    newQueue->tail = NULL;
    newQueue->length = 0;
    return newQueue;
}

int IsTheChainedQueueEmpty(ChainedQueue* queue)
{
    if(queue == NULL)
        return 1;
    if (queue->length == 0)
        return 1;
    return 0;
}

void Enqueue(ChainedQueue* queue, void* newElement)
{
    Node* newNode;

    if (queue == NULL)
    {
        printf("The queue is null.");
        return;
    }

    newNode = malloc(sizeof(Node));
    newNode->element = newElement;
    newNode->next = NULL;

    if (IsTheChainedQueueEmpty(queue) == 1)
        queue->head = newNode;
    else
        queue->tail->next = newNode;

    queue->tail = newNode;
    queue->length += 1;
}

void* Dequeue(ChainedQueue* queue)
{
    Node* removedNode;
    void* elementToReturn;

    if (IsTheChainedQueueEmpty(queue) == 1)
    {
        printf("The queue is empty or null.\n");
        return NULL;
    }

    removedNode = queue->head;
    elementToReturn = removedNode->element;

    queue->head = queue->head->next;
    queue->length -= 1;

    free(removedNode);
    return elementToReturn;
}

void DesallocateChainedQueue(ChainedQueue* queue, void (*ElementDesallocationFunction)())
{
    Node* currentNode;

    if (queue == NULL)
        return;

    while (queue->head != NULL)
    {
        currentNode = queue->head;
        queue->head = queue->head->next;

        ElementDesallocationFunction(currentNode->element);
        free(currentNode);
    }

    free(queue);
}

void ShowChainedQueueStatus(ChainedQueue* queue)
{
    if (queue == NULL)
    {
        printf("The queue is null.");
        return;
    }

    if (IsTheChainedQueueEmpty(queue) == 1)
    {
        printf("The queue is empty.\n");
        return;
    }

    printf("Queue status: Length = %i \n", queue->length);
}

void ReadDataFromAllElements(ChainedQueue* queue, void (*ElementReadFunction)())
{
    Node* currentNode;
    int counter;
    
    if (IsTheChainedQueueEmpty(queue) == 1)
    {
        printf("The queue is empty or null.\n");
        return;
    }

    currentNode = queue->head;
    counter = 0;

    while(currentNode != NULL)
    {
        printf("Element %i: \n", counter);
        ElementReadFunction(currentNode->element);

        currentNode = currentNode->next;
        counter += 1;
    }
}