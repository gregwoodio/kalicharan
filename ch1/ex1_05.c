/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 1, exercise 5
 *
 * Write a function which, given two date structures, d1 and d2, returns
 * -1 if d1 comes before d2, 0 if d1 is the same as d2 and 1 if d1 comes
 * after d2.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct date {
    char day, month;
    int year;
} Date;

int compareDate(Date*, Date*);
Date* initDate(char, char, int);

int main() {
    int y;
    char d, m;
    Date *d1, *d2;
    printf("Enter date one (DD MM YYYY):");
    scanf("%d %d %d", &d, &m, &y);
    d1 = initDate(d, m, y);

    printf("Enter date two (DD MM YYYY):");
    scanf("%d %d %d", &d, &m, &y);
    d2 = initDate(d, m, y);

    printf("Compare dates: %d\n", compareDate(d1, d2));
    return;
}

int compareDate(Date *d1, Date *d2) {
    if (d1->year < d2->year) 
        return -1;
    else if (d1->year > d2->year)
        return 1;
    else if (d1->month < d2->month)
        return -1;
    else if (d1->month > d2->month)
        return 1;
    else if (d1->day < d2->day)
        return -1;
    else if (d1->day > d2->day)
        return 1;
    else 
        return 0;
}

Date* initDate(char day, char month, int year) {
    Date* d = (Date*) malloc(sizeof(Date));
    d->day = day;
    d->month = month;
    d->year = year;
}
