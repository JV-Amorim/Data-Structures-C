#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "developer.h"

void StackUtilizationExample()
{
    Stack* stack;
    Developer* dev;

    stack = StackFactory(2);

    Push(stack, DeveloperFactory());
    Push(stack, DeveloperFactory());
    Push(stack, DeveloperFactory());

    ShowStackStatus(stack);

    dev = Pop(stack);
    ReadDeveloperData(dev);
    free(dev);

    ShowStackStatus(stack);

    DesallocateStack(stack, &DesallocateDeveloper);
}

int main()
{
    StackUtilizationExample();
    return 0;
}