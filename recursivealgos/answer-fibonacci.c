// Recursive Fibonacci function
#include <stdio.h>

int Fibonacci(int n)
{
    if (n == 0 || n == 1)
       return 1;
   else 
       return Fibonacci(n-1) + Fibonacci(n-2);   
}

int main()
{
   printf("%d\n", Fibonacci(0));
   printf("%d\n", Fibonacci(1));
   printf("%d\n", Fibonacci(10));
   
   return 0;
}    

