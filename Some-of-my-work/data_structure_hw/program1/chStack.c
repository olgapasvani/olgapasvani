//char Stack implementation

#include "chStack.h"

void InitializeStack(Stack *s){
    s->ItemList = NULL;
}

int Empty(Stack *s){
    return (s->ItemList == NULL);  //if the function returns 1 the stack is empty 
}                                 // if the function returns 0 the stack is not empty

int Full(Stack *s){
    return 0;       //we assume the stack is not empty because it can grow any time as a linked structure
}

void Push(Stack *s, char newItem){
    StackNode *new;     //create new node
    new = (StackNode *) malloc(sizeof(StackNode)); //to add a new item we must create space for it
    if(new == NULL){
        perror("system storage is exhausted\n");
    }else{
        //we will put the new item's address on top of the stack
        new->Item = newItem;
        new->Link = s->ItemList;
        s->ItemList = new;
    }
}

void Pop(Stack *s, char *item){
    StackNode *temp;
    if(Empty(s)){
        printf("Attempt to pop the empty stack\n");
    } else{
        temp = s->ItemList;
        *item = temp->Item;
        s->ItemList = temp->Link;
        free(temp);
    }
}