/* 
 * Data Structures in C by Noel Kalicharan
 * Chapter 1, Exercise 2
 *
 * Write a program to read names and phone numbers into a structure 
 * array. Request a name and print the person's phone number. Use binary
 * search to look up the name.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 30
#define MAX_ENTRIES 15

typedef struct person {
    char first[MAX_NAME];
    char last[MAX_NAME];
    char phone[MAX_NAME];
} Person;

void readNumbers(FILE*, Person*);
void binarySearch(Person*, char*, int, int);

int main() {
    int i;
    char name[MAX_NAME];
    Person phonebook[MAX_ENTRIES];
    FILE *in = fopen("phonenumbers.txt", "r");

    readNumbers(in, phonebook);

    /* 
     * Print out all entries in the phonebook. 
    for (i = 0; i < MAX_ENTRIES; i++) {
        printf("%d. %s, %s - %s\n", i, phonebook[i].last, phonebook[i].first, phonebook[i].phone);
    }
    */
    printf("Enter a last name: ");
    scanf("%s", &name);
    i = 0;
    binarySearch(phonebook, name, 0, MAX_ENTRIES - 1);

}

void readNumbers(FILE *in, Person *phonebook) {
    int i, j;
    Person tmp;

    /* Populate array */
    for (i = 0; i < MAX_ENTRIES; i++) {
        fscanf(in, "%s %s %s", phonebook[i].first, phonebook[i].last, phonebook[i].phone);
    }

    /* Sort the phonebook by last name */
    for (i = 1; i < MAX_ENTRIES; i++) {
        tmp = phonebook[i];
        j = i - 1;
        while (j >= 0 && strcmp(phonebook[j].last, tmp.last) > 0) {
            phonebook[j + 1] = phonebook[j];
            --j;
        }
        phonebook[j + 1] = tmp;
    }
}

void binarySearch(Person *phonebook, char *name, int lo, int hi) {
    int i;
    if (hi < lo) {
        printf("Not found.\n");
        return;
    }
    
     /* Find the middle */
    i = (lo + hi) / 2;

    /* If the middle value matches, print it out. */
    if (strcmp(phonebook[i].last, name) == 0) {
        printf("%s, %s - %s\n", phonebook[i].last, phonebook[i].first, phonebook[i].phone);
        return;
    /* Otherwise, if it's above or below search that half of the array */
    } else if (strcmp(phonebook[i].last, name) > 0) {
        return binarySearch(phonebook, name, lo, i - 1);
    } else if (strcmp(phonebook[i].last, name) < 0) {
        return binarySearch(phonebook, name, i + 1, hi);
    }
}
