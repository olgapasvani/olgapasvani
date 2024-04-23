#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//Question's function
void sortStack(Stack *inS, Stack *sortedS){
    int temp;
    Pop(inS, &temp);
    Push(sortedS, temp); //push the first element in to the new stack
    while (!Empty(inS)) {
        Pop(inS, &temp);
        while (!Empty(sortedS) && sortedS->ItemList->Item > temp) {/*αν η κορυφή της νεας μας στοιβας είναι μεγαλύτερη
        του καινούριου στοιχείου που πήραμε από την σοίβα εισόδου τότε το αφαιρούμε από την καινούρια στοίβα και το επιστρέφουμε στην στοίβα εισόδου*/
            int item;
            Pop(sortedS, &item);
            Push(inS, item);
        }
        Push(sortedS, temp); /*όταν δεν υπάρχει πλέον μεγαλύτερο στοιχείο στην καινούρια στοίβα από αυτό που προσπαθούμε
        να πρόσθεσουμε τότε το κανουμε push στην sortedS*/
    } //επαναλαμβάνουμε μέχρι να αδειάσει η στοίβα εισόδου
}

int main(){
    Stack *inputStack, sortedStack;
    InitializeStack(inputStack);

    for (int i = 0; i < 6; i++)
    {
        Push(inputStack, rand());//filling the input stack with random values
    }

    InitializeStack(&sortedStack);
    sortStack(inputStack, &sortedStack); //sort the random values

    int x;
    for (int i = 0; i < 6; i++) //pop the values out of the sorted stack
    {
        Pop(&sortedStack, &x);
        printf("%d\n", x);
    }
    return 0;
}