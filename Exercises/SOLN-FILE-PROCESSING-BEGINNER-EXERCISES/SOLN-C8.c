/*
    Challenge #8 solution to CCPROG2 File-Processing-Beginner-Exercises.PDF.
    
    Illustrates mixed mode file processing to modify the contents of existinging data.	 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"  // student structure header file
#define FILENAME "STUDENTS.BIN"

void
Change_Grade(FILE *fp, int key)
{
	int found = 0;
	float new_grade;
	struct studentTag s;

    fseek(fp, 0, SEEK_SET); // reposition at the start of the file
	
	while (!found && fread(&s, sizeof(struct studentTag), 1, fp) == 1) {
		if (key == s.ID)
			found = 1;	
	}
	
	if (found) {
		printf("%d  %s %s  %.2f\n", s.ID, s.name.first, s.name.last, s.grade);
		printf("Input new grade: ");
		scanf("%f", &new_grade);
		
		// update student record in the binary file
		s.grade = new_grade;                                       // step 1: modify the affected member
		fseek(fp, (int)-sizeof(struct studentTag), SEEK_CUR);      // step 2: go back to previous file position
        fwrite(&s, sizeof(struct studentTag), 1, fp);              // step 3: write the data into the file
		fflush(fp);												   // step 4: make sure to fflush() the file       
	}
		
	else
		printf("NOT FOUND\n");
	 
	// NOTE: DON'T CLOSE THE FILE HERE
}


int 
main()
{		
	FILE *fp;
	int key;
	
	fp = fopen(FILENAME, "rb+");   // NOTE: make it is rb+ for MIXED-MODE
	if (fp != NULL) {
		do {
			printf("Input ID Number: ");
			scanf("%d", &key);
			if (key != -999)
				Change_Grade(fp, key);
				
			printf("\n");
		} while (key != -999);  // -999 is the sentinel value
	    printf("END SEARCH\n");
	    
		fclose(fp);	
	}	
	else {
		fprintf(stderr, "%s not found, exiting...\n", FILENAME);
		exit(1);
	}
	
	
	return 0;
}

