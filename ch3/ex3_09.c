/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 3 Exercise 9
 *
 * You are given two pointers b1 and b2 each pointing to a binary number
 * stored as in 7. You must return a pointer to a newly created linked list
 * representing the binary sum of the given numbers with the least 
 * significant bit at the head of the list and the  most significant bit
 * at the tail of the list. Write functions to do this in two ways:
 *  (i) using the functions from 7 and 8
 *  (ii) performing 'bit by bit' addition
 */

#include "ex.h"

int main() {
    int n;
    NodePtr b1, b2, sum;
    printf("Enter first number: ");
    scanf("%d", &n);
    b1 = toBinary(n);
    printf("Enter second number: ");
    scanf("%d", &n);
    b2 = toBinary(n);
    printf("\n   ");
    printList(b1);
    printf("\n + ");
    printList(b2);
    sum = addBinary(b1, b2, 0);
    printf("\n = ");
    printList(sum);
    printf("\n");
}
