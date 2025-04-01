/* header file for CCPROG2-File-Processing-Exercises.PDF file problems */

typedef char String20[21];

struct nameTag {
    String20 first;
    String20 last;
};

struct studentTag {
    int ID; // student ID number
    struct nameTag name;
    float grade;
};
