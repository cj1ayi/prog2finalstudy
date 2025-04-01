/*
    Challenge #6 solution to CCPROG2 File-Processing-Beginner-Exercises.PDF.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"  // student structure header file
#define SOURCE_FILENAME "STUDENTS.BIN"
#define DEST_FILENAME   "STUDENTS-REV.BIN"


void
Read_Student_Bin_File(char *source_filename, char *dest_filename)
{
	FILE *source_fp;  // input/source file pointer
	
	source_fp = fopen(source_filename, "rb");
	if (source_fp != NULL) {
            struct studentTag s;
            int filesize; 
	    int n; // number of student data
            FILE *dest_fp; // output/dest file pointer 
	    
            // we first determine how many student structure data are stored in the source binary file
            fseek(source_fp, 0, SEEK_END); // move to file position of EOF
            filesize = ftell(source_fp); // EOF file position is also the number of bytes in the file, i.e., its filesize
            n = filesize/sizeof(struct studentTag);  // we then get the number of student structures

      	    dest_fp = fopen(dest_filename, "wb");
            // read student data in reversed order (sequence), start from the last structure back to the 1st record
            for (int i = 0; i < n; i++) {
                // move to the correct file position first 
                fseek(source_fp, -(i+1) * sizeof(struct studentTag), SEEK_END);  // study the offset value (2nd parameter)
                fread(&s, sizeof(s), 1, source_fp);
                printf("%d  %s %s  %.1f\n", s.ID, s.name.first, s.name.last, s.grade); 

                // we then write to the output destination binary file
                fwrite(&s, sizeof(s), 1, dest_fp);            
            }

            // 
            // Challenge to student: change the fseek() such that the origin is SEEK_SET.  What should be offset?
	    //
	
	    fclose(source_fp);
            fclose(dest_fp);
	}
	else {
		fprintf(stderr, "%s not found, exiting...\n", SOURCE_FILENAME);
		exit(1);
	}
}

int 
main()
{		
	Read_Student_Bin_File(SOURCE_FILENAME, DEST_FILENAME);
	return 0;
}



