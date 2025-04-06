#include <stdio.h>

void AccessArray2(int A[], int index, int n)
{
    if (index < n ) {
       AccessArray2(A, index+1, n);
       printf("A[%d] = %d\n", index, A[index]); 
    }
}

int main()
{
    int A[5] = {10, 20, 30, 40, 50};

    AccessArray2(A, 0, 5);

    return 0;
}
