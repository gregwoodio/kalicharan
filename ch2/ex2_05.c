/* 
 * Data Structures in C by Noel Kalicharan
 * Chapter 2 Exercise 5
 *
 * In main there are three int variables, a b and c. Write a function
 * which, when called, stores the sum of a and b in c so that c is 
 * changed in main.
 */

#include <stdio.h>

void sum(int*, int*, int*);

int main() {
    int a, b, c;
    a = 5; 
    b = 7;
    c = 9;
    
    printf("a: %d b:%d c:%d\n", a, b, c);
    sum(&a, &b, &c);
    printf("a: %d b:%d c:%d\n", a, b, c);

    return 0;
}

void sum(int *x, int *y, int *z) {
    *z = *x + *y;
    return;
}
