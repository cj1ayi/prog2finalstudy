#include <stdio.h>
#include <string.h>

#define MAX 12

typedef char String20[20]; 

typedef struct nameTag { 
    String20 first; 
    String20 last; 
}; 

typedef struct studentTag { 
    int ID; // student ID number 
    struct nameTag name;  
    float grade;  
};

void inputStudent(struct studentTag *new_student)
{
    printf("Input ID: ");
    scanf("%d", &new_student->ID);
    printf("Input first name: ");
    scanf("%s", new_student->name.first);
    printf("Input last name: ");
    scanf("%s", new_student->name.last);
    printf("Input grade: ");
    scanf("%f", &new_student->grade);

}

void appendStudent(struct studentTag new_student)
{
    FILE *fp;

    fp = fopen("STUDENTS.txt", "a");

    if (fp == NULL)
        printf("Error\n");
    else{
        fprintf(fp, "%d %s %s \t\t%.1f\n", new_student.ID, new_student.name.first, 
                                    new_student.name.last, new_student.grade);
    }
    fclose(fp);

}


int main()
{
    struct studentTag new_student;
    
    inputStudent(&new_student);
    appendStudent(new_student);

    return 0;
}