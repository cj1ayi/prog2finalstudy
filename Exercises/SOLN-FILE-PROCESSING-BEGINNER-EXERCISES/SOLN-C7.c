/*
    Challenge #7 solution to CCPROG2 File-Processing-Beginner-Exercises.PDF.
    
    Illustrates the use of fseek() to reposition the file to the beginning for linear searching on a binary file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"  // student structure header file
#define FILENAME "STUDENTS.BIN"

void
Linear_Search(FILE *fp, int key)
{
	int found = 0;
	struct studentTag s;

    fseek(fp, 0, SEEK_SET); // reposition at the start of the file
	
	while (!found && fread(&s, sizeof(struct studentTag), 1, fp) == 1) {
		if (key == s.ID)
			found = 1;	
	}
	
	if (found)
		printf("%d  %s %s  %.2f\n", s.ID, s.name.first, s.name.last, s.grade);
		
	else
		printf("NOT FOUND\n");
	 
	// NOTE: DON'T CLOSE THE FILE HERE
}


int 
main()
{		
	FILE *fp;
	int key;
	
	fp = fopen(FILENAME, "rb");
	if (fp != NULL) {
		do {
			printf("Input ID Number: ");
			scanf("%d", &key);
			if (key != -999)
				Linear_Search(fp, key);
				
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



