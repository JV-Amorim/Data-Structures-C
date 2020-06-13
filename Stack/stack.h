#ifndef STACK_H
#define STACK_H

typedef struct _Stack Stack;
struct _Stack
{
    int capacity;
    int top;
    void **elements;
};

Stack* StackFactory(int capacity);
int IsTheStackEmpty(Stack* stack);
void Push(Stack* stack, void* newElement);
void* Pop(Stack* stack);
void DesallocateStack(Stack* stack, void (*ElementDesallocationFunction)());
void ShowStackStatus(Stack* stack);

#endif