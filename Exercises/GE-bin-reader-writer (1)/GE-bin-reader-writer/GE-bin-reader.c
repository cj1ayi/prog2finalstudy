/*
    GE-bin-reader.c 

    INSTRUCTIONS: 
    1. Compile and run first the accompanying program GE-bin-writer.c which will create the binary file SOMEDATA.BIN.
       Make sure that you have this binary file in the same folder as this C source code.

    2. Draw a memory map of SOMEDATA.BIN (refer to the example memory map shown in our CCPROG2 slides on Binary File Processing).
       It will help you answer this Graded Exercise.

    3. FILL-UP the 15 blanks all of which are denoted as
            
             offset = ___; 

       by assigning the appropriate integer value to the variable named as offset.
       
       The value of the offset will be used as the second parameter in  the fseek() function calls.
       
       HINT: use ftell() to determine if you are in the correct file position before doing the fread() from the binary file.      

    4. If you did everything correctly, your program should produce exactly the same output as the accompanying file EXPECTED.TXT. 
*/

#include <stdio.h>
#include <string.h>

#define BINARYFILE "SOMEDATA.BIN"
   
struct sampleTag {
    double D[5];
    int n;
};

int main()
{
    FILE *fp;
    char temp_ch;
    int temp_int;
    double temp_double;
    char temp_str1[27];
    char temp_str2[5];
    int LIST[5];
    struct sampleTag temp_struct;
    long int offset;
  
    fp = fopen(BINARYFILE, "rb");  // read binary
    if (fp != NULL) {              
        //
        //  For this exercise, assign the appropriate WHOLE NUMBER (constant value) to the offset variable.
        //
	// 1. Objective: read '#' from the file into temp_ch 
	offset = 83;   // What should be the value of offset to achieve the objective?        
        fseek(fp, offset, SEEK_SET);
        fread(&temp_ch, sizeof(char), 1, fp);
        printf("1. %c\n", temp_ch); // displays #

	// 2. Objective: read 3.1416 from the file into temp_double 
	offset = 27;           
        fseek(fp, offset, SEEK_SET);
        fread(&temp_double, sizeof(double), 1, fp);
        printf("2. %lf\n", temp_double);  // displays 3.141600

	// 3. Objective: read the 5 integers -10 to -50 from the file into LIST
	offset = ___;           
        fseek(fp, offset, SEEK_SET);
        fread(LIST, sizeof(LIST), 1, fp);
        printf("3. %d %d\n", LIST[0], LIST[4]);  // displays -10 -50

        // 4. Objective: read the characters 'A' to 'Z' and the null null byte from the file into temp_str
	offset = ___;           
        fseek(fp, offset, SEEK_SET);
        fread(temp_str1, sizeof(char), 27, fp);
        printf("4. %s\n", temp_str1);  // displays ABCDEFGHIJKLMNOPQRSTUVWXYZ

        // 5. Objective: read the structure value from the file into temp_struct
	offset = ___;           
        fseek(fp, offset, SEEK_SET);
        fread(&temp_struct, sizeof(struct sampleTag), 1, fp);
        printf("5. %d %lf %lf\n", temp_struct.n, temp_struct.D[0], temp_struct.D[4]);   // displays 5 -20.000000 -100.000000
        
    	// 6. Objective: read '#' from the file into temp_ch 
	offset = ___;           
        fseek(fp, offset, SEEK_END);
        fread(&temp_ch, sizeof(char), 1, fp);
        printf("6. %c\n", temp_ch);  // displays #

	// 7. Objective: read 3.1416 from the file into temp_double 
	offset = ___;           
        fseek(fp, offset, SEEK_END);
        fread(&temp_double, sizeof(double), 1, fp);
        printf("7. %lf\n", temp_double);  // displays 3.141600

	// 8. Objective: read the 5 integers -10 to -50 from the file into LIST
	offset = ___;           
        fseek(fp, offset, SEEK_END);
        fread(LIST, sizeof(LIST), 1, fp);
        printf("8. %d %d\n", LIST[0], LIST[4]);  // displays -10 -50

        // 9. Objective: read the characters 'A' to 'Z' and the null null byte from the file into temp_str
	offset = ___;           
        fseek(fp, offset, SEEK_END);
        fread(temp_str1, sizeof(char), 27, fp);
        printf("9. %s\n", temp_str1);  // displays ABCDEFGHIJKLMNOPQRSTUVWXYZ  

        // 10. Objective: read the structure value from the file into temp_struct
	offset = ___;           
        fseek(fp, offset, SEEK_END);
        fread(&temp_struct, sizeof(struct sampleTag), 1, fp);
        printf("10. %d %lf %lf\n", temp_struct.n, temp_struct.D[0], temp_struct.D[4]);  // displays 5 -20.000000 -100.000000

        // 11. Objective: read 3.1416 from the file into temp_double 
	offset = ___;           
        fseek(fp, offset, SEEK_CUR);
        fread(&temp_double, sizeof(double), 1, fp);
        printf("11. %lf\n", temp_double);    // displays 3.141600

        // 12. Objective: read -50 from the file into temp_int
	offset = ___;           
        fseek(fp, offset, SEEK_CUR);
        fread(&temp_int, sizeof(int), 1, fp);
        printf("12. %d\n", temp_int);  // displays -50

        // 13. Objective: read the characters WXYZ up to the null byte from the file into temp_str2
	offset = ___;           
        fseek(fp, offset, SEEK_CUR);
        fread(temp_str2, sizeof(char), 5, fp);
        printf("13. %s\n", temp_str2);  // displays WXYZ

        // 14. Objective: read character 'E' from the file into temp_ch
	offset = ___;           
        fseek(fp, offset, SEEK_CUR);
        fread(&temp_ch, sizeof(char), 1, fp);
        printf("14. %c\n", temp_ch);  // displays E

        // 15. Objective: set the file position to the EOF location
	offset = ___;           
        fseek(fp, offset, SEEK_CUR); 
        printf("15. Current file position is %ld\n", ftell(fp));  // displays 104

        fclose(fp);  
    }
    else {
	fprintf(stderr, "ERROR: %s not found! Make sure to run the GE-16-writer.c program first.\n");        
    }
    return 0;
}
