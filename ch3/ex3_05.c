/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 3 Exercise 5
 *
 * Write a function that takes 3 arguments -  a pointer to a list of 
 * integers, and two integers n and j - and inserts n after the jth 
 * element of the list. If j is 0, n is inserted at the head of the list. 
 * If j is greater than the number of elements in the list, n is inserted 
 * after the last one.
 */

#include "ex.h"

int main() {

    int n, j;
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

    printf("\nEnter another number. \n");
    scanf("%d", &n);

    printf("\nInsert at what index? \n");
    scanf("%d", &j);

    head = insertAt(head, n, j);

    printList(head);

    /* Free list */
    freeList(head);
    printf("\n");
    return 0;

}
