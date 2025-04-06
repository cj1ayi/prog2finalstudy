#include <stdio.h>

long int SumArray(int A[], int index, int n)
{
    if (index < n) // recursive case
       return A[index] + SumArray(A, index+1, n); // NON-TAIL END
    else  // base case
       return 0;
}

int main()
{
    int A[5] = {10, 20, 30, 40, 50};

    printf("Sum of array elements = %ld\n", SumArray(A, 0, 5));

    return 0;
}
