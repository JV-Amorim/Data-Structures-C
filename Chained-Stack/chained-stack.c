#include <stdio.h>
#include <stdlib.h>
#include "chained-stack.h"

ChainedStack* ChainedStackFactory()
{
    ChainedStack* newStack = malloc(sizeof(ChainedStack));
    newStack->length = 0;
    newStack->top = NULL;
    return newStack;
}

int IsTheChainedStackEmpty(ChainedStack* stack)
{
    if (stack == NULL)
        return 1;
    if (stack->top == NULL)
        return 1;
    return 0;
}

void Push(ChainedStack* stack, void* newElement)
{
    Node* newNode;
    
    if (stack == NULL)
        return;

    newNode = malloc(sizeof(Node));
    newNode->previous = stack->top;
    newNode->element = newElement;

    stack->top = newNode;
    stack->length += 1;
}

void* Pop(ChainedStack* stack)
{
    Node* removedNode;
    void* elementToReturn;

    if (IsTheChainedStackEmpty(stack) == 1)
    {
        printf("The stack is empty or null.\n");
        return NULL;
    }

    removedNode = stack->top;
    elementToReturn = removedNode->element;

    stack->top = stack->top->previous;
    stack->length -= 1;

    free(removedNode);
    return elementToReturn;
}

void DesallocateChainedStack(ChainedStack* stack, void (*ElementDesallocationFunction)())
{
    Node* currentNode;

    if (stack == NULL)
        return;

    while (stack->top != NULL)
    {
        currentNode = stack->top;
        stack->top = stack->top->previous;
        
        ElementDesallocationFunction(currentNode->element);
        free(currentNode);
    }

    free(stack);
}
    

void ShowChainedStackStatus(ChainedStack* stack)
{
    if (stack == NULL)
    {
        printf("The stack is null.");
        return;
    }

    if (IsTheChainedStackEmpty(stack) == 1)
    {
        printf("The stack is empty.\n");
        return;
    }

    printf("Stack status: Length = %i \n", stack->length);
}

void ReadDataFromAllElements(ChainedStack* stack, void (*ElementReadFunction)())
{
    Node* currentNode;
    int counter;
    
    if (IsTheChainedStackEmpty(stack) == 1)
    {
        printf("The stack is empty or null.\n");
        return;
    }

    currentNode = stack->top;
    counter = stack->length;

    while (currentNode != NULL)
    {
        printf("Element %i: \n", counter);
        ElementReadFunction(currentNode->element);

        currentNode = currentNode->previous;
        counter -= 1;
    }
}