//This program reads two DNA sequences,
//finds the maximum common sequence between them, and prints it.
//Additionally, there are some example files located in the same
//folder as the program that the user can utilize as input via the command line
//for example sample1.dna sample2.dna

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int Same(char *, char *, char *, int , int );

int main(int argc, char **argv){
    if (argc != 3)              //If the user doesn't enter two files the program ends
    {
        printf("Error: arguments missing. Usage: ./dna dnafile1 dnafile2\n");
        exit(1);
    }

    FILE *file1 = fopen(argv[1], "rb");
    FILE *file2 = fopen(argv[2], "rb");
    if (file1 == NULL) {
        printf("Error: cannot open file %s\n", argv[1]);
        exit(1);
    }
    if (file2 == NULL) {
        printf("Error: cannot open file %s\n", argv[2]);
        fclose(file1);   //closing the firsτ file before the program stops
        exit(1);
    }

//-----------------------------------------------
    //We find the number of characters in the file
    char v = getc(file1);
    int count = 0;
    while (v != EOF)
    {
        if (v!='A' && v!='G' && v!='T' && v!='C')
        {
            v = getc(file1);
            continue;
        }
        v = getc(file1);
        count++;
    }
    
    fseek(file1, 0, SEEK_SET); //go to the first character of the file
    v = getc(file1);
    char *string1 = (char*)malloc(sizeof(char)*(count));
    for (int i = 0; i < count && v!=EOF; i++) //we put the file's characters in to the string array
    {
        if (v!='A' && v!='G' && v!='T' && v!='C' && v!=EOF)
        {
            i--;
            v = getc(file1);
            continue;
        }
        string1[i] = v;
        v = getc(file1);
    }
    
    //we do the same thing for the second file
    v = getc(file2);
    int count2 = 0;
    while (v != EOF)
    {
        if (v!='A' && v!='G' && v!='T' && v!='C' )
        {
            v = getc(file2);
            continue;
        }
        v = getc(file2);
        count2++;
    }
    fseek(file2, 0, SEEK_SET);
    v = getc(file2);
    char *string2 = (char*)malloc(sizeof(char)*(count2));
    for (int i = 0; i < count2 && v!=EOF; i++)
    {
        if (v!='A' && v!='G' && v!='T' && v!='C' && v!=EOF)
        {
            i--;
            v = getc(file2);
            continue;
        }
        string2[i] = v;
        v = getc(file2);
    }

//----------------------------------------------
    
    int small; //we find the smaller DNA sequences
    if (count<count2)
    {
        small = count;
    }else
    {
        small = count2;
    }
    char *common = (char*)malloc(sizeof(char)*(small+1));//make the array that will keep the bigger common sequences
    int maxS;
    if (count<count2)
    {//The Same functions finds the biggest common sequences
        maxS = Same(common, string1, string2, count, count2); 
    }else
    {
        maxS = Same(common, string2, string1, count2, count);
    }
    
    for (int i = 0; i < maxS; i++)//we print the sequence
    {
        if (common[i] == 'A' || common[i] == 'C' || common[i] == 'G' || common[i] == 'T')
        {
            printf("%c", common[i]);
        }
        
    }
    printf("\n");

    free(string1);
    free(string2);
    free(common);
    fclose(file1);
    fclose(file2);
    exit(0);
}



/*In this function, we compare the elements of the large array with those of the small array.
We start by comparing the elements of both arrays node by node, beginning from the start of each array.
Next, we increment the offset variable (i) of the large array (dna2[]) by one node each time.
With each iteration, we compare the two arrays again. However, in each subsequent comparison,
the large array starts with the node indicated by the updated offset variable (i).*/

int Same(char * MaxCommon, char *dna1, char *dna2, int count1, int count2){
    int max = 0;
    char *Common = (char*)malloc(sizeof(char)*(count1+1));
    int NumOfComm = 0;

    for(int i = 0; i <=count2; i++){ //we will compare every sequence of the big DNA, starting from the first character
        int temp = i; //use a temporary variable to ne able to

        if (i == 0){ //We want to ensure that the function compares 
                    //the sequences at the end of the small array (dna1[]) 
                    //with the sequences at the first nodes of the large array (dna2[])
            int temp2;
            for(int j = count1 -1; j >= 0; j = j-1)//Start comparing from the last element of the small DNA sequence
             {                                     //until we reach the first element  
                temp = 0; //we want to start comparing from the first element of dna2[]
                temp2 = j;//and the j element of dna1[] (remind that j has firstly the last element's offset and we reduce it with the above loop)
                
                for(int n = temp2; n < count1; n++){
                    if (dna2[temp] == dna1[n] && (dna2[temp] != EOF && dna1[n] != EOF)){ //check if the nodes are same
                        Common[NumOfComm] = dna1[n];    //we put this element in the temprary array for common sequences
                        NumOfComm++;
                    }else{
                        if (NumOfComm > max){  //we check if the sequence we found is the biggest one
                            max = NumOfComm;
                            for (int n = 0; n < max; n++){
                                MaxCommon[n] = Common[n];
                            }
                        }
                        NumOfComm = 0;
                    }
                    temp++;
                    if (temp>count2) break; //if we have reach the large array's (dna2[]) limits we stop the loop
                }
            }
            NumOfComm = 0;
            temp = i; 
        }
        
/*---This is what happens next in the case where i == 0, and it is the only step for all other cases where i > 0---------*/

        for (int j = 0; j <= count1; j++){
            if (dna2[temp] == dna1[j] && (dna2[temp] != EOF && dna1[j] != EOF))
            {//if both nodes contain the same character (and it is not the end of the array)
                Common[NumOfComm] = dna1[j];  //we put this element in the temprary array for common sequences
                NumOfComm++;  //and increase the counter of same characters
            }else{            //if we the arrays nodes are different
                if (NumOfComm > max){ //we check if the sequence we found is the biggest one
                    max = NumOfComm;
                    for (int n = 0; n < max; n++){
                        MaxCommon[n] = Common[n];
                    }
                }
                NumOfComm = 0; //and put 0 in the counter of same elements
            }
            temp++;  //After every comparison, we also update the temporary offset of the larger array

            if (temp>count2) break; //if we have reach the large array's (dna2[]) limits we stop the loop
        }
    }
    free(Common);
    return max;
}
