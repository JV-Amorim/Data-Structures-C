#include <stdio.h>
#include <stdlib.h>
#include "chained-queue.h"
#include "developer.h"

void ChainedQueueUtilizationExample()
{
    ChainedQueue* queue;
    Developer* dev;

    queue = ChainedQueueFactory();

    Enqueue(queue, DeveloperFactory());
    Enqueue(queue, DeveloperFactory());
    Enqueue(queue, DeveloperFactory());

    ShowChainedQueueStatus(queue);

    printf("\nReading all queue data without removing elements: \n");

    ReadDataFromAllElements(queue, &ReadDeveloperData);

    printf("\nReading all queue data while removing elements: \n");

    dev = Dequeue(queue);
    ReadDeveloperData(dev);
    free(dev);

    dev = Dequeue(queue);
    ReadDeveloperData(dev);
    free(dev);

    dev = Dequeue(queue);
    ReadDeveloperData(dev);
    free(dev);

    ShowChainedQueueStatus(queue);

    DesallocateChainedQueue(queue, &DesallocateDeveloper);
}

int main()
{
    ChainedQueueUtilizationExample();
    return 0;
}