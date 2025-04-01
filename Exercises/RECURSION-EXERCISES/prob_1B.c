/* 

  Name   : Lastname, Firstname (in CAPITAL LETTERS)
  Section:

*/


/*
   Write a RECURSIVE implementation of the function SumOfDigits(n).
   It should return the sum (also called total) of the digits in
   parameter n. 


   Examples:  
      SumOfDigits(8)  returns 8
      SumOfDigits(32) returns 5, i.e., the sum of two digits 2 and 3.
      SumOfDigits(893) returns 20, i.e., the sum of three digits 3, 9 and 8. 

   

*/

int 
SumOfDigits(int n)
{
    /* You are NOT ALLOWED to declare a local variable here. */
    /* DO NOT use printf() inside this function. */
  

    /* 
             THINK!!!
       
       1. What is the base case?
       2. What is the recursive case?
    */


}



int main()
{
    int nNum;

    printf("Input a positive integer: ");
    scanf("%d", &nNum);  // assume nNum is positive
    
    printf("SumOfDigits(%d) is %d.\n", nNum, SumOfDigits(nNum));

    return 0;

}

 
