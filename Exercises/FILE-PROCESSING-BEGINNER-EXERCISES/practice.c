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

void readFile(struct studentTag student[MAX])
{
    char ch;
    int i = 0;
    FILE *fp;

    fp = fopen("STUDENTS.txt", "r");

    do
    {
        fscanf(fp,"%d %s %s %f", &student[i].ID, student[i].name.first, 
                                student[i].name.last, &student[i].grade );//diretso number
        i++;
    } while (fscanf(fp, "%c", &ch) != EOF);
}


void printStudents(struct studentTag student[MAX])
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d %s %s  \t%.1f\n", student[i].ID, student[i].name.first, student[i].name.last, student[i].grade);
    } //gay
}



int main()
{
    struct studentTag student[MAX];
    
    readFile(student);
    printStudents(student);

    return 0;
}