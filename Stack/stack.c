#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

Stack* StackFactory(int capacity)
{
    Stack* newStack = malloc(sizeof(Stack));
    newStack->capacity = capacity;
    newStack->top = -1;
    newStack->elements = malloc(sizeof(void*) * capacity);
    return newStack;
}

int IsTheStackEmpty(Stack* stack)
{
    if (stack == NULL)
        return 1;
    if (stack->top == -1)
        return 1;
    return 0;
}

void Push(Stack* stack, void* newElement)
{
    if (stack == NULL)
        return;
    
    if (stack->top == stack->capacity - 1)
    {
        printf("The stack is full.\n");
        return;
    }

    stack->top += 1;
    stack->elements[stack->top] = newElement;
}

void* Pop(Stack* stack)
{
    void* elementToReturn;

    if (IsTheStackEmpty(stack) == 1)
    {
        printf("The stack is empty or null.\n");
        return NULL;
    }
    
    elementToReturn = stack->elements[stack->top];
    stack->top -= 1;

    return elementToReturn;
}

void DesallocateStack(Stack* stack, void (*ElementDesallocationFunction)())
{
    int counter;

    if (stack == NULL)
        return;

    for (counter = 0; counter <= stack->top; counter++)
        ElementDesallocationFunction(stack->elements[counter]);
    
    free(stack->elements);
    free(stack);
}

void ShowStackStatus(Stack* stack)
{
    if (stack == NULL)
    {
        printf("The stack is null. \n");
        return;
    }

    if (IsTheStackEmpty(stack) == 1)
    {
        printf("The stack is empty.\n");
        return;
    }
    
    printf("Stack status: Capacity = %i | Top = %i \n", stack->capacity, stack->top + 1);
}