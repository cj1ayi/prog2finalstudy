#include <stdio.h>

// prints a sequence of integers from 1 up to n
void Series2(int n)
{
    if (n > 0) {
       Series2(n-1);  // NON-TAIL-END RECURSION -- when the recursion is NOT
                      // the last INSTRUCTION/STEP to be performed.
       printf("n = %d\n", n);  // NOTE: printf() can only execute after Series2()!
    }
}

int main()
{
    int n;
    
    n = 3;
    Series2(n);
    return 0;
}
