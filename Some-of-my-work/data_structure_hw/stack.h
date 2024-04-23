#include <stdio.h>
#include <stdlib.h>

typedef struct StackList{
    int Item;
    struct StackList *Link;
}StackNode;

typedef struct stack{
    StackNode *ItemList;
}Stack;

//typedef struct StackList StackNode;
//typedef struct stack Stack;

void InitializeStack(Stack *);
int Empty(Stack *);
int Full(Stack *);
void Push(Stack *, int);
void Pop(Stack *, int *);