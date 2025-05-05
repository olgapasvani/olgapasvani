#include <stdio.h>
#include <stdlib.h>

//Δυαδική αναζήτηση με πολυπλοκότητα χρόνου Ο(logn)
//και χώρου Ο(1)
int Binary_search(int element, int *array, int n){
    int mid, left = 0, right = n-1;
    while (left<=right)
    {
        mid = (left + right)/2;
        if (array[mid] == element)return mid;
        else if (array[mid] < element)
        {
            left = mid + 1;
        }
        else if (array[mid] > element){
            right = mid - 1;
        }
    }
    printf("The %d element couldn't be found\n", element);
    return -1; 
}

//Ταξινόμηση κατ'επιλογή, πολυπλοκότητα O(n^2)
void Selection_Sort(int *array, int n){
    int i, j, min;
    for (i = 1; i <=n-1; i++)
    {
        min = i-1;
        for (j = i; j<=n-1; j++)
        {
            if (array[j]<array[min]) min = j;
            
            int temp = array[i-1];
            array[i-1] = array[min];
            array[min] = temp;
        } 
    }
}

//Φυσαλίδα, πολυπλοκότητα O(n^2)
void bubblesort(int n, int *array){
    for (int i = 1; i <= n-1; i++)
    {
        for (int j = n-1; j >= i; j--)
        {
            if (array[j-1]>array[j])
            {
                int temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
            }
        }
    }  
}


//Γρηγορόττερες μεθόδοι

//Πολυπλοκότητα O(nlog(n)) μπορεί να καθυστερεί όμως εξαιτίας 
//της δέσμευσης και αποδέσμευσης χώρου στην στίβα
void merge_sort(int *array, int l, int r, int m){
    int n1 = m - l, n2 = r-m;
    int left[n1], right[n2];
    for (int i = 0; i < n1; i++) left[i] = array[l+i];
    for (int j = 0; j < n2; j++) right[j] = array[m+l+j];
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j]) array[k++] = left[i++];
        else array[k++] = right[i++];        
    }
    while(i < n1) array[k++] = left[i++];
    while (j <n2) array[k++] = right[j++];    
}

void quicksort(int *x, int lower, int upper){

}


union examp
{
    unsigned char name : 3;
    unsigned char lastN : 3;
    unsigned int age : 4;
};


int main(){
    int M = 34, n;
    int N = 36;
    int **array = malloc(M * sizeof(int*));
    if (!array)
    {
        perror("array allocation");
        exit(1);
    }
    
    for (int i = 0; i < M; i++){
        array[i] = malloc(N * sizeof(int));
        if (!array[i])
        {
            perror("array[i] allocation");
            exit(1);
        }
    }
    if(M < N ? printf("%d\n", N):1)
    printf("%d\n", M>>1);

    //////

    union examp me;
    me.name = '1';
    me.lastN = '0';
    me.age = 5;
    printf("%d\n", sizeof(me.age));
    return 0;
}