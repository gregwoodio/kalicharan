/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 2 Exercise 4
 *
 * In main() there are two int variables, a and b. Write a function which,
 * when called, interchanges the values of and be so that the change is 
 * known in main.
 */

#include <stdio.h>

void swap(int*, int*);

int main() {
    int x, y;
    x = 5;
    y = 7;
    printf("X: %d Y: %d\n", x, y);
    swap(&x, &y);
    printf("X: %d Y: %d\n", x, y);
    return 0;
}

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
    return;
}
