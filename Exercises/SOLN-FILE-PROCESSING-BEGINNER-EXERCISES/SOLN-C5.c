/*
    Challenge #5 solution to CCPROG2 File-Processing-Beginner-Exercises.PDF.
	
	Note: two alternative solutions are presented for your reference. 
	
	Can you the similarity in logic with Challenge #1?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"  // student structure header file
#define FILENAME "STUDENTS.BIN"


// note: change the #if 1 below to #if 0 to run 2nd solution
#if 1

// 1st solution
void
Read_Student_Bin_File(char *filename)
{
	FILE *fp;
	struct studentTag s;
	
	fp = fopen(filename, "rb");
	if (fp != NULL) {
		while (fread(&s, sizeof(struct studentTag), 1, fp) == 1) {  // fread() if successful should return the same value as 3rd parameter
			printf("%d  %s %s  %.1f\n", s.ID, s.name.first, s.name.last, s.grade);
			// note: don't worry about spacing format for now... 
		}
		
		fclose(fp);
	}
	else {
		fprintf(stderr, "%s not found, exiting...\n", FILENAME);
		exit(1);
	}
}

#else

// 2nd solution illustrates use of feof()
void
Read_Student_Bin_File(char *filename)
{
	FILE *fp;
	struct studentTag s;
	
	fp = fopen(filename, "rb");
	if (fp != NULL) {
                printf("Solution number 2\n");
		do {
			fread(&s, sizeof(struct studentTag), 1 , fp);
			if (!feof(fp))  // Q: remove this line if (!feof(fp)), retain the printf().  What will happen?		
				printf("%d  %s %s  %.1f\n", s.ID, s.name.first, s.name.last, s.grade);
		} while (!feof(fp));
		
		fclose(fp);
	}
	else {
		fprintf(stderr, "%s not found, exiting...\n", FILENAME);
		exit(1);
	}
}

#endif


int 
main()
{		
	Read_Student_Bin_File(FILENAME);
	return 0;
}



