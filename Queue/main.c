#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "developer.h"

void QueueUtilizationExample()
{
    Queue* queue;
    Developer* dev;

    queue = QueueFactory(3);

    Enqueue(queue, DeveloperFactory());
    Enqueue(queue, DeveloperFactory());
    Enqueue(queue, DeveloperFactory());

    dev = Dequeue(queue);
    ReadDeveloperData(dev);
    free(dev);

    dev = Dequeue(queue);
    ReadDeveloperData(dev);
    free(dev);

    Enqueue(queue, DeveloperFactory());
    Enqueue(queue, DeveloperFactory());

    dev = Dequeue(queue);
    ReadDeveloperData(dev);
    free(dev);

    dev = Dequeue(queue);
    ReadDeveloperData(dev);
    free(dev);

    DesallocateQueue(queue, &DesallocateDeveloper);
}

int main()
{
    QueueUtilizationExample();
    return 0;
}