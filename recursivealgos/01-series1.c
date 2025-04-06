#include <stdio.h>


// prints a sequence of integers from n down to 1
void Series1(int n)
{
    if (n > 0) {  // recursive case
       printf("n = %d\n", n);
       Series1(n-1);  // notice also that the LAST INSTRUCTION/STEP is a recursive function call
                      // this kind of recursion is called "TAIL-END RECURSION"
    }
  
    // base case is when the if condition is false, i.e., when n = 0 or lower
}

int main()
{
    int n;
    
    n = 3;
    Series1(n);
    return 0;
}
