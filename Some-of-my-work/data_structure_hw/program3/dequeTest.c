#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

int main(){ //Εδώ έχουμε ένα μικρό πρόγραμμα που αναδεικνύει τις λειτουργίες της ουράς διπλού άκρου
    Deque test;
    Create(&test);
    Push(&test, 3);
    Enqueue(&test, 4);
    int size = SizeOf(&test);
    printf("The size of the deque is: %d\n", size);
    printf("The deque contains the following elements: ");
    Print(&test);

    return 0;
}