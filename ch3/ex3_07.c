/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 3 Exerice 7
 *
 * Write a function which, given a pointer to a linked list of bits stored
 * as in exercise 6, traverses the list once and returns the decimal 
 * equivalent of the binary number.
 */

#include "ex.h"

int main() {
    int n;
    NodePtr head;

    printf("Please enter an integer: \n");
    scanf("%d", &n);

    head = toBinary(n);

    printList(head);

    printf("\nIn decimal: %d\n", toDecimal(head));

    freeList(head);

    return 0;
}
