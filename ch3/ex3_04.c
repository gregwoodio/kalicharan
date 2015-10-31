/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 3 Exercise 4
 *
 * Write a function to free all the nodes of a given linked list.
 *
 */

#include "ex.h"

int main() {

    int n;
    NodePtr np, head = NULL, prev;
    
    /* Make a list */
    printf("Enter numbers, and 0 to stop.\n");
    if (scanf("%d", &n) != 1) n = 0;
    while (n != 0) {
        np = mkNode(n);
        if (head == NULL) head = np;
        else prev->next = np;
        prev = np;
        if (scanf("%d", &n) != 1) n = 0;
    }

    /* Display list */
    printList(head);

    /* Free list */
    freeList(head);
    printf("\n");
    return 0;

}
