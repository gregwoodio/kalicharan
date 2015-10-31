/* 
 * Data Structures in C by Noel Kalicharan
 * Chapter 3 Exercise 1
 *
 * Write a function which, given a pointer to a linked list of integers, 
 * returns 1  * if the list is sorted in ascending order and 0 otherwise.
 *
 * Compile with
 * gcc -lm ex1.c ex.h exfunc.h
 */

#include "ex.h"

int main() {
    
    NodePtr np, head = NULL, last;
    int n;
    printf("Please enter numbers, or 0 to stop.\n");
    if (scanf("%d", &n) != 1) n = 0;
    while (n != 0) {
        np = mkNode(n);
        if (head == NULL) head = np;
        else last->next = np;
        last = np;
        if (scanf("%d", &n) != 1) n = 0;
    }

    if (inAscendingOrder(head) == 1) {
        printf("This list is in ascending order.\n");
    } else {
        printf("This list is not in ascending order.\n");
    }

    return;
}
