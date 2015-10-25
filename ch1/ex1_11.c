/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 1 Exercise 11
 *
 * A data file contains registration information for six courses - CS20A,
 * CS21A, CS29A, CS30A, CS35A and CS36A. Each line of data consists of a 
 * 7 digit student registration number followed by six (ordered) values,
 * each of which is a 0 or 1. A value of 1 indicates that the student is 
 * registered for the corresponding course; 0 means he is not. Thus 1 0 1
 * 0 1 1 means that the student is registered for CS20A, CS29A, CS35A and
 * CS36A, but not for CS21A and CS30A. You may assume that there are no
 * more than 100 students and a registration number 0 ends the data. Write
 * a program to read the data and produce a class list for each course. 
 * Each list begins on a new page and consists of the registration numbers
 * for those students taking the course.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct student {
    int studentnum;
    int classes[6];
    struct student *next;
} Student;

Student* makeStudent(int);
void printClassList(char*, int, Student*);

int main() {

    char *token, buffer[30];
    int studentnumber, x, i;
    Student *top = NULL, *curr, *prev;
    FILE *in = fopen("classlist.txt", "r");
    if (in == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fgets(buffer, 29, in);
    token = strtok(buffer, " ");
    studentnumber = atoi(token);
    while (studentnumber != 0) {
        curr = makeStudent(studentnumber);
        for (i = 0; i < 6; i++) {
            token = strtok(NULL, " ");
            x = atoi(token);
            curr->classes[i] = x;
        }
        if (top == NULL) {
            top = curr;
        } else {
            prev->next = curr;
        }
        prev = curr;
        fgets(buffer, 29, in);
        token = strtok(buffer, " ");
        studentnumber = atoi(token);
    }

    printClassList("CS20A", 0, top);
    printClassList("CS21A", 1, top);
    printClassList("CS29A", 2, top);
    printClassList("CS30A", 3, top);
    printClassList("CS35A", 4, top);
    printClassList("CS36A", 5, top);

    return 0;
}

Student* makeStudent(int studentnumber) {
    Student* student = (Student*)malloc(sizeof(Student));
    student->studentnum = studentnumber;
    student->next = NULL;
    return student;
}

void printClassList(char *name, int num, Student *student) {
    printf("*** %s ***\n", name);
    while (student != NULL) {
        if (student->classes[num] == 1) {
            printf("%d\n", student->studentnum);
        }
        student = student->next;
    }
    return;
}
