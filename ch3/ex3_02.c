/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 3 Exercise 2
 *
 * Write code to reverse the nodes of a linked list by manipulating
 * the pointer fields only. No new nodes must be created.
 */

#include "ex.h"

int main() {
    NodePtr head = NULL, np, prev;
    int n;
    printf("Enter numbers, then 0 to stop.\n");
    if (scanf("%d", &n) != 1) n = 0;
    while (n != 0) {
        np = mkNode(n);
        if (head == NULL) {
            head = np;
        } else {
            prev->next = np;
        }
        prev = np;
        if (scanf("%d", &n) != 1) n = 0;
    }
    printf("\nYour list:\n");
    printList(head);

    printf("\nReversed: \n");
    printList(reverse(head));
    printf("\n");
    
    return 0;

}
