#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "developer.h"

void QueueUtilizationExample()
{
    Queue* queue;
    Developer* dev;

    queue = QueueFactory();

    Enqueue(queue, DeveloperFactory());
    Enqueue(queue, DeveloperFactory());
    Enqueue(queue, DeveloperFactory());

    ShowQueueStatus(queue);

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

    ShowQueueStatus(queue);

    DesallocateQueue(queue, &DesallocateDeveloper);
}

int main()
{
    QueueUtilizationExample();
    return 0;
}