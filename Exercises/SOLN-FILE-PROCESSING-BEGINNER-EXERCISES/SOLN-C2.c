/*
    Challenge #2 solution to CCPROG2 File-Processing-Beginner-Exercises.PDF.
    
    This solution shows how to process 1 input text file and 2 output text files.
	
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"  // student structure header file
#define STUDENTS "STUDENTS.TXT"
#define PASS     "PASS.TXT"
#define FAIL     "FAIL.TXT" 

void
Create_Pass_Fail_Files(char *filename1, char *filename2, char *filename3)
{
	FILE *fp_students;
	FILE *fp_pass;
	FILE *fp_fail;
	struct studentTag s;
	
	fp_students = fopen(filename1, "r");
	if (fp_students != NULL) {
		fp_pass = fopen(filename2, "w");   // let's assume that files were created successfully
		fp_fail = fopen(filename3, "w");		
		while (fscanf(fp_students, "%d %s %s %f", &s.ID, s.name.first, s.name.last, &s.grade) == 4 ) {
			if (s.grade > 0.0 )
				fprintf(fp_pass, "%d  %s %s  %.1f\n", s.ID, s.name.first, s.name.last, s.grade);
			else 
				fprintf(fp_fail, "%d  %s %s  %.1f\n", s.ID, s.name.first, s.name.last, s.grade);
			// note: don't worry about spacing format for now... 
		}
		
		fclose(fp_students);
		fclose(fp_pass);
		fclose(fp_fail);
	}
	else {
		fprintf(stderr, "%s not found, exiting...\n", filename1);
		exit(1);
	}
}



int 
main()
{		
	Create_Pass_Fail_Files(STUDENTS, PASS, FAIL);
	return 0;
}



