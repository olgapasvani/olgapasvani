//char Stack Interface

#include <stdio.h>
#include <stdlib.h>

typedef struct StackList{
    char Item;
    struct StackList *Link;
}StackNode;

typedef struct stack{
    StackNode *ItemList;
}Stack;

void InitializeStack(Stack *);
int Empty(Stack *);
int Full(Stack *);
void Push(Stack *, char);
void Pop(Stack *, char *);