/*
   GE-bin-writer.c  

   INSTRUCTIONS: 
   1.  Study the codes in this program.  Take note of the sequence of fwrite() and the data that are being written to the binary file.
   
   2.  Compile this program, and run the executable tfile to binary file SOMEDATA.BIN.  This binary file will be needed by the
       reader program GE-bin-reader.c.
*/
#include <stdio.h>
#include <string.h>
   
struct sampleTag {
    double D[5];
    int n;
};

int main()
{
    FILE *fp;
    char ch = '#';
    double d = 3.1416;
    int A[5] = {-10, -20, -30, -40, -50};
    char str[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    struct sampleTag temp;
  
    temp.n = 5;
    for (int i = 0; i < 5; i++)
        temp.D[i] = A[i] * 2.0;
    
    fprintf(stdout, "sizeof(struct sampleTag) = %d\n", (int)sizeof(struct sampleTag));  
    // NOTE: assume that sizeof(struct sampleTag) is 48 bytes.

    fp = fopen("SOMEDATA.BIN", "wb");          
        fwrite(str, sizeof(str), 1, fp);       
        fwrite(&d, sizeof(double), 1, fp);     
        fwrite(&temp, sizeof(struct sampleTag), 1, fp);  
        fwrite(&ch, sizeof(char), 1, fp);      
        fwrite(A, sizeof(int), 5, fp);         
    fclose(fp);  

    /*
       HINT: Draw a memory map first of the contents of SOMEDATA.BIN file 
             before completing the codes in GE-bin-reader.c file.
    */ 
    return 0;
}
