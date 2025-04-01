/*
    Challenge #1 solution to CCPROG2 File-Processing-Beginner-Exercises.PDF.
	
    Note: two alternative solutions are presented for your reference. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"  // student structure header file
#define FILENAME "STUDENTS.TXT"


// note: change the #if 1 below to #if 0 to run 2nd solution
#if 1

// 1st solution
void
Read_Student_Text_File(char *filename)
{
	FILE *fp;
	struct studentTag s;
	
	fp = fopen(filename, "r");
	if (fp != NULL) {
		while (fscanf(fp, "%d %s %s %f", &s.ID, s.name.first, s.name.last, &s.grade) == 4 ) {
			
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
Read_Student_Text_File(char *filename)
{
	FILE *fp;
	struct studentTag s;
	
	fp = fopen(filename, "r");
	if (fp != NULL) {
                printf("Solution number 2\n");
		do {
			fscanf(fp, "%d %s %s %f", &s.ID, s.name.first, s.name.last, &s.grade);
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
	Read_Student_Text_File(FILENAME);
	return 0;
}



