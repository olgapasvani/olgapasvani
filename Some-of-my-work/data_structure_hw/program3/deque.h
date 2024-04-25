/*This is the Deque structure. It works like the queue structure but
here we can push and pop elements both from the beggining and 
the end of the deque*/

#ifndef DEQUE_H
#define DEQUE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct DequeList{
    int item;
    struct DequeList *prev;
    struct DequeList *next;    
}DequeNode;

typedef struct deque{
    DequeNode *first, *last;
}Deque;

static DequeNode *link = NULL; //we need this, to link the first tow nodes 

void Create(Deque *);
int IsEmpty(Deque *);
int SizeOf(Deque *);
void Enqueue(Deque *, int);
void Push(Deque *, int);
int Pop(Deque *);
int Dequeue(Deque *);
void Print(Deque *);

#endif