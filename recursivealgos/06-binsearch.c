#include <stdio.h>

// recursive binary search
int BinarySearch(int key, int A[], int low, int high)
{
    int mid = low + (high - low)/2;
 
    if (low > high)
       return -1;  // base case: -1 means key not found
    else if (key == A[mid]) // Eureka!
            return mid; // base case: key found    
    else if (key < A[mid]) // search lower half
            return BinarySearch(key, A, low, mid-1);
    else // key > A[mid]   // search upper half
            return BinarySearch(key, A, mid+1, high);
}

int main()
{
    int A[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};   
               // 0   1   2   3   4   5   6   7   8    9 
    int index;

    int key = 77;

    index = BinarySearch(key, A, 0, 9);
    if (index == -1)
       printf("key %d not found!", key);
    else 
       printf("key %d matched %d at index %d\n", key, A[index], index);
   
    return 0;
}
