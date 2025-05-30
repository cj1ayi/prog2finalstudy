#include <stdio.h>

/*
   Recursive linear search.
   If key is found, return the index where it was found, otherwise return -1.
*/
int LinearSearch(int key, int A[], int index, int n)
{
    if (index < n) {
       if (A[index] == key)
          return index;
       else 
          return LinearSearch(key, A, index+1, n);
    }
    else 
       return -1;
}

int main()
{
    int A[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};   
               // 0   1   2   3   4   5   6   7   8    9 
    int index;

    int key = 100;

    index = LinearSearch(key, A, 0, 10);
    if (index == -1)
       printf("key %d not found!", key);
    else 
       printf("key %d matched %d at index %d\n", key, A[index], index);
   
    return 0;
}
