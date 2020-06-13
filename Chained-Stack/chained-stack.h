#ifndef CHAINED_STACK_H
#define CHAINED_STACK_H

typedef struct _Node Node;
struct _Node
{
    Node* previous;
    Node* next;
    void** element;
};

typedef struct _ChainedStack ChainedStack;
struct _ChainedStack
{
    int length;
    Node* top;
};

ChainedStack* ChainedStackFactory();
int IsTheChainedStackEmpty(ChainedStack* stack);
void Push(ChainedStack* stack, void* newElement);
void* Pop(ChainedStack* stack);
void DesallocateChainedStack(ChainedStack* stack, void (*ElementDesallocationFunction)());
void ShowChainedStackStatus(ChainedStack* stack);

void ReadDataFromAllElements(ChainedStack* stack, void (*ElementReadFunction)());

#endif