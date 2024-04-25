/*This program calculates the sum of all prime square numbers 
that are within a range of natural numbers.
The user has to enter two numbers in the command
line as inputs for the limits of the range of natural numbers*/
//for example ./mirror 1 1000

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int First_Root(int, long long int);


int main(int argc, char **argv){
    if (argc != 3) //if the user doesn't give two numbers the program ends
    {
        printf("Program needs to be called as: ./mirror low high\n");
        return 1;
    }
    long long int low = atoll(argv[1]);
    long long int high = atoll(argv[2]);

//All the inappropriate inputs
    if (low > high)
    {
        printf("The 'low' limit must be smaller than the 'high' limit\n");
        return 1;
    }
    if(low < 1 || high > 1000000000000000)
    {
        printf("The input is out of limits\n");
        return 1;
    }
//----------------
    
    long int root = First_Root(low, high); //we want the first root of the range of numbers  
    long long int cn, mirror, sum = 0;

    long int int_result;
    long double double_result;

    if(root % 2 == 0)root++;
    for (long int i = root; i*i <= high; i+= 2)/*We look for prime square numbers
    by checking the squares roots of the numbers within the given range*/
    {    
        //We check it is not prime        
        if (i % 3 == 0 || i % 5 == 0)continue;
        int prime = 1;
        for (int divisor = 5; (divisor*divisor) <= i; divisor+=2)
        {
            if(i % divisor == 0)
            {
                prime = 0;
                break;
            }
        }
        if (prime == 0) continue;

        //If the root is prime we make it's squere and then it's mirror number
        cn = i*i;
        //-----We make it's Mirror Number
        long long int temp = cn;
        mirror = 0;
        while (temp > 0)
        {
            mirror = mirror * 10 + temp % 10;
            temp = temp/10;
        }

        //If the number is palindromic we skip it
        if (cn == mirror)continue;
        
        //-----end of making the mirror number--------

        int MirrorPerSq = 0;
        //2. We check if the mirror nubmer is a perfect squere
        int_result = sqrt(mirror);
        double_result = sqrt(mirror);
        if (int_result == double_result)MirrorPerSq = int_result;

        if(MirrorPerSq == 0)continue;//if the mirror is not a perfect squer we go to the next number

        //If it is a perfect squer we check if the mirror's root is prime
        prime = 1;
        if(MirrorPerSq % 2 == 0 || MirrorPerSq % 3 == 0)
        {
            prime = 0;
        }else{
            for (int divisor = 5; (divisor*divisor) <= MirrorPerSq; divisor+=2)
            {
                if(MirrorPerSq % divisor == 0)
                {
                    prime = 0;
                    break;
                }
            }
        }
        if (prime == 0)continue;//If the root of mirror is not prime then we check the next number

            sum = sum + cn;  
    }
    printf("%lld\n", sum);
    return 0;
}

//We will find the root of the first perfect squere
long int First_Root(int low, long long int high){
    long int int_result;
    long double double_result;
    for(long int i = low; i<= high; i = i+1){
        int_result = sqrt(i);
        double_result = sqrt(i);
        if (int_result == double_result)return int_result;
        
    }
    return 0;
}