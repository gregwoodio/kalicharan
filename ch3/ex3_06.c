/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 3 Exercise 6
 *
 * Write a function which, given an integer n, converts n to binary, and
 * stores each bit in one node of a linked list with the least significant
 *  bit at the head of the list and the most significant bit at the tail. 
 *  For example, given 13, the bits are stored in the order 1 0 1 1 from 
 *  head to tail. Return a pointer to the head of the list.
 */

#include "ex.h"

int main() {
    int n;
    NodePtr head;

    printf("Please enter an integer: \n");
    scanf("%d", &n);

    head = toBinary(n);

    printList(head);
    freeList(head);
    printf("\n");

    return 0;
}
