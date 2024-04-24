//In this program, we sort some numbers
//that have been pushed into a stack by using another stack

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
        while (!Empty(sortedS) && sortedS->ItemList->Item > temp) {/*If the top element of the new stack is bigger
        than the input stack's new element, then we pop the top element from the new stack and push it in to the input stack*/
            int item;
            Pop(sortedS, &item);
            Push(inS, item);
        }
        Push(sortedS, temp); /*when there is not any other bigger element than the one we are tryng to push in the new stack
        then we push it in the sortedS (our new stack)*/
    } //Repeat until the input stack is empty
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