#include "deque.h"

void Create(Deque *d){
    d->first = NULL;
    d->last = NULL;
}

int IsEmpty(Deque *d){  //if both first and last nodes are empty then the deque is empty
    return(d->first == NULL && d->last == NULL);
}

int SizeOf(Deque *d){
    DequeNode *temp;
    int count = 0;
    if (IsEmpty(d)) return 0;
    temp = d->first;    //we start counting from the first node
    while (temp != NULL)//to the last
    {
        count++;
        temp = temp->next;
    }
    free(temp);
    return count;
}

void Enqueue(Deque *d, int Item){
    DequeNode *new = (DequeNode *)malloc(sizeof(DequeNode)); //create space for the new element
    new->item = Item; //store it
    new->next = NULL; //since we push to the end it will become the last element so new->next = NULL
    if (d->last == NULL){//if we push to the end for the first time
        d->last = new;
        if (link != NULL) {//if there is an element before it, then it is stored in the link pointer, so we link them
            link->next = d->last;
            d->last->prev = link;
        }else {//if it is the first element we push to the deque at all
            link = d->last;
            d->last->prev = NULL;
        }
    } else{//if we already have first and last elements   
        new->prev = d->last;
        d->last->next = new;
        d->last = new;
    }
}

void Push(Deque *d, int Item){
    DequeNode *new = (DequeNode *)malloc(sizeof(DequeNode));
    new->item = Item;
    new->prev = NULL;
    if (d->first == NULL) { //If the deque is empty
        d->first = new;    //the new node becomes the first node
        d->first->next = NULL;
        if (link != NULL){ //but if we have already put an element at the end of the deque, we conect the two nodes
            link->prev = d->first;
            d->first->next = link;
        } else {
            link = d->first; //If it is the first element of deque at all it becomes the 'link' that connects the first two "last" and "fisrt" nodes
            d->first->next = NULL; //If it is the first element of deque at all then the 'next' pointer gets NUL
        }
    } else {    
        new->next = d->first;//if we already have first and last nodes we just put the new element at the beggining of the deque
        d->first->prev = new;
        d->first = new;
    }
}

int Pop(Deque *d){
    int Item = d->first->item;//store the node's value
    d->first = d->first->next; //set as first node the second one
    free(d->first->prev); //free the previous first node
    d->first->prev = NULL;
    return Item;   //return the value of the poped node 
}

int Dequeue(Deque *d){ //it works like the Pop function, but here
//we set as last node the node before it, and we free previous one
    int Item = d->last->item;
    d->last = d->last->prev;
    free(d->last->next);
    d->last->next = NULL;
    return Item;
}

void Print(Deque *d){
    DequeNode *temp = (DequeNode *)malloc(sizeof(DequeNode));
    temp = d->first; //we start from the first node
    while (temp != NULL) //and we print till the last one
    {
        printf("%d ", temp->item);
        temp = temp->next;
    }
    printf("\n");
}

