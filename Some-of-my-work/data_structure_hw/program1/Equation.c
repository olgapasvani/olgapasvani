//This program takes as input an equation without left parentheses
//and balances the equation using a stack
//The user will be asked to enter the unbalanced equation

#include <stdio.h>
#include <stdlib.h>
#include "chStack.h"

int main()
{
    Stack equation; //the stack that will end up with the balanced equation
    InitializeStack(&equation);
    char *input = (char *)malloc(50 * sizeof(char *));
    printf("Please enter the equation\n");
    scanf("%s", input);

    int count = 0;
    for (int i = 0; input[i] != '\0'; i++)
    {
        count++;    //counting the number of the equation's characters
    }

    int right = 0;  //it will count the number of the remain unbalanced parenthesis
    for (int i = count-1; i >= 0; i--) {
    //we put the data from the end to the start,
    //so when we pop them they will be in right order
        if (input[i] == ')')
        {
            right++;
        }

        if (right > 0 && (input[i] == '*' || input[i] == '/'))
        { //if we have unbalanced parenthesis and we have reach the point where should be a left parenthesis
         //we push '(' to the stack
            Push(&equation, '(');
            right--;  //one unbalanced parenthesis less
            count++; //one more character to the equation
        }

        Push(&equation, input[i]);
    }

    while (right > 0)
    {  //if there is a right parentesis ')' that includes the entire equation
      //we balance it too
        Push(&equation, '(');
        right--;
        count++;
    }
    
    char x;
    for (int i = 0; i < count; i++)
    {
        Pop(&equation, &x);
        printf("%c", x);
    }
    printf("\n");
    free(input);
    return 0;
}