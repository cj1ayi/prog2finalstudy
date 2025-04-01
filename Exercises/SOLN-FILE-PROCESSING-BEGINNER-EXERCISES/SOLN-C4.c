/*
    Challenge #4 solution to CCPROG2 File-Processing-Beginner-Exercises.PDF.
    
    This solution shows how to produce an output binary file from a given input text file.		
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"  // student structure header file
#define TXTFILE "STUDENTS.TXT"
#define BINFILE "STUDENTS.BIN"

void
Create_Binary_File(char *filename1, char *filename2)
{
	FILE *fp_txt;
	FILE *fp_bin;
	struct studentTag s;
	
	fp_txt = fopen(filename1, "r");
	if (fp_txt != NULL) {
		fp_bin = fopen(filename2, "wb");   // binary file: let's assume that files were created successfully
		while (fscanf(fp_txt, "%d %s %s %f", &s.ID, s.name.first, s.name.last, &s.grade) == 4 ) {
			fwrite(&s, sizeof(struct studentTag), 1, fp_bin); // write to the binary file
		}
		
		fclose(fp_txt);
		fclose(fp_bin);	}
	else {
		fprintf(stderr, "%s not found, exiting...\n", filename1);
		exit(1);
	}
}



int 
main()
{		
	Create_Binary_File(TXTFILE, BINFILE);
	return 0;
}



