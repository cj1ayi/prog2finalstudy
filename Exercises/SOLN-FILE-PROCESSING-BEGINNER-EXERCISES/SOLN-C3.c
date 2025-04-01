/*
    Challenge #3 solution to CCPROG2 File-Processing-Beginner-Exercises.PDF.
	
	Shows how to append data to a text file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"  // student structure header file
#define FILENAME "STUDENTS.TXT"

void
Append_Student_Data(char *filename, struct studentTag s)
{
	FILE *fp;
	
	fp = fopen(filename, "a");  // NOTE: append mode
	if (fp != NULL) {
  		fprintf(fp, "%d  %s %s  %.2f\n", s.ID, s.name.first, s.name.last, s.grade);
		fclose(fp);
	}
	else {
		fprintf(stderr, "%s not found, exiting...\n", FILENAME);
		exit(1);
	}
}

void
Input_Student_Data(struct studentTag *ptr)
{
    printf("Input ID: ");
    scanf("%d", &ptr->ID);
    
    printf("Input first name: ");
    scanf("%s", ptr->name.first);
        
    printf("Input last name: ");
    scanf("%s", ptr->name.last);
	
    printf("Input grade: ");
    scanf("%f", &ptr->grade);	
}

int 
main()
{		
    struct studentTag student;
    
    Input_Student_Data(&student);
	Append_Student_Data(FILENAME, student);
	
	return 0;
}



