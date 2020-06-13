#include <stdio.h>
#include <stdlib.h>
#include "chained-stack.h"
#include "developer.h"

void ChainedStackUtilizationExample()
{
    ChainedStack* stack;
    Developer* dev;

    stack = ChainedStackFactory();

    Push(stack, DeveloperFactory());
    Push(stack, DeveloperFactory());
    Push(stack, DeveloperFactory());

    ShowChainedStackStatus(stack);

    printf("\nReading all stack data without removing elements: \n");
    
    ReadDataFromAllElements(stack, &ReadDeveloperData);

    printf("\nReading all stack data while removing elements: \n");

    dev = Pop(stack);
    ReadDeveloperData(dev);
    free(dev);

    dev = Pop(stack);
    ReadDeveloperData(dev);
    free(dev);

    dev = Pop(stack);
    ReadDeveloperData(dev);
    free(dev);

    ShowChainedStackStatus(stack);

    DesallocateChainedStack(stack, &DesallocateDeveloper);
}

int main()
{
    ChainedStackUtilizationExample();
    return 0;
}