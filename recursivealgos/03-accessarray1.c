#include <stdio.h>

void AccessArray1(int A[], int index, int n)
{
    if (index < n ) {
       printf("A[%d] = %d\n", index, A[index]);
       AccessArray1(A, index+1, n);
    }
}

int main()
{
    int A[5] = {10, 20, 30, 40, 50};

    AccessArray1(A, 0, 5);

    return 0;
}
