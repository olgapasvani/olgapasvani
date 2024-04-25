#include <stdio.h>
#include <stdlib.h>
#include "CircularList.h"

int main(void){
    CircularList *test = (CircularList *)malloc(sizeof(CircularList));
    Create(test);
    Add(test, 1);
    Add(test, 2);
    Add(test, 3); //Η σειρά με την οποία έχουν προστεθεί οι αριθμοί,
    //έφοσον κάθε προσθήκη μπαίνει δίπλα στον cursor είναι 1 3 2
    printf("Cursor points to the node that contains: %d\n", test->cursor->item);
    Advance(test);
    printf("After moving cursor to the next node it points to the node that contains: %d\n", test->cursor->item);
    int Item = Remove(test);
    Item = Remove(test);
    Item = Remove(test);
    printf("We have remove all elements from the list and if we try to remove again we get this message:\n");
    Item = Remove(test);
    return 0;
}