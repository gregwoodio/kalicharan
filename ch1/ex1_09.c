/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 1 Exercise 9
 *
 * A file contains the names and distances jumbed by athletes in a long
 * jump competition. Using a structure to hold a name and distance (which
 * is itself a structure, as in 8 above) write a program to read the data
 * and print a list of names and distance jumped in order of merit (best 
 * jumper first).
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 30
#define NUM_JUMPERS 8

typedef struct length {
    int m, cm;
} Length;

typedef struct jumper {
    char* name;
    Length* distance;
    struct jumper *next;
} Jumper;

int compareLength(Length*, Length*);
Jumper* makeJumper(char*, char*, int, int);
void sortList(Jumper*, int, int);
void printList(Jumper*, int);

int main() {

    Jumper jumpers[NUM_JUMPERS];
    char first[MAX_NAME], last[MAX_NAME];
    int m, cm, i = 0;

    FILE *in = fopen("longjump.txt", "r");
    if (in == NULL) {
        printf("Error reading file.");
        return 1;
    }

    while (fscanf(in, "%s %s %d %d", first, last, &m, &cm) != EOF) {
        jumpers[i++] = *makeJumper(first, last, m, cm);
    }

    sortList(jumpers, 0, NUM_JUMPERS - 1);
    printList(jumpers, NUM_JUMPERS);

}

int compareLength(Length *l1, Length *l2) {
    if (l1->m > l2->m)
        return -1;
    else  if (l1->m < l2->m)
        return 1;
    else if (l1->cm > l2->cm)
        return -1;
    else if (l1->cm < l2->cm)
        return 1;
    else
        return 0;
}

Jumper* makeJumper(char *first, char *last, int m, int cm) {
    char *name = (char*)malloc(sizeof(char) * (MAX_NAME + MAX_NAME));
    Jumper *jp = (Jumper*)malloc(sizeof(Jumper));
    Length *lp = (Length*)malloc(sizeof(Length));
    lp->m = m;
    lp->cm = cm;
    jp->distance = lp;
    strcpy(name, first);
    strcat(name, " ");
    strcat(name, last);
    jp->name = name;
    return jp;
}

void sortList(Jumper *jumpers, int lo, int hi) {
    int j, i, highest;
    Jumper tmp;
    for (j = lo; j < hi; j++) {
        highest = j;
        for (i = j + 1; i <= hi; i++) {
            if (compareLength(jumpers[i].distance, jumpers[highest].distance) == -1) {
                highest = i;
            }
        }
        tmp = jumpers[highest];
        jumpers[highest] = jumpers[j];
        jumpers[j] = tmp;
    }
}

void printList(Jumper *jumpers, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%s, %d %d\n", jumpers[i].name, jumpers[i].distance->m, jumpers[i].distance->cm);
    }
    return;
}

