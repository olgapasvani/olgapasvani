#include "CircularList.h"

void Create(CircularList *cl){
    cl->cursor = NULL;
}

void Add(CircularList *cl, int Item){
    ListNode *new = (ListNode *)malloc(sizeof(ListNode));
    new->item = Item;
    if (cl->cursor == NULL) {
        cl->cursor = new;
        cl->cursor->link = cl->cursor;
    } else {
        new->link = cl->cursor->link;
        cl->cursor->link = new;
    }    
}

int Remove(CircularList *cl){
    int Item;
    ListNode *temp;
    if (cl->cursor == NULL) {
        printf("Attempt to remove from empty list\n");
        cl->cursor = NULL;
        Item = -1;
    } else if (cl->cursor->link == cl->cursor) {
        Item = cl->cursor->item;
        free(cl->cursor);
        cl->cursor = NULL;
    } else {
        temp = cl->cursor->link;
        Item = temp->item;
        cl->cursor->link = temp->link;
        free(temp);        
    }
    return Item;
}

void Advance(CircularList *cl){
    cl->cursor = cl->cursor->link;
}