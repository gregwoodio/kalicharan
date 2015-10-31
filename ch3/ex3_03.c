/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 3 Exercise 3
 *
 * Write a function to sort a linked list as follows:
 * 1. Find the largest value in the list.
 * 2. Delete it from its position and insert it at the head of the list.
 * 3. Starting from what is now the second element, repeat (a) and (b).
 * 4. Starting from what is now the third element, repeat (a) and (b).
 * Continue until sorted.
 */

#include "ex.h"

int main() {
       
    NodePtr head = NULL, np, prev;
    int n;

    printf("Enter numbers, then 0 to stop.\n");
    if (scanf("%d", &n) != 1) n = 0;
    while (n != 0) {
        np = mkNode(n);
        if (head == NULL) head = np;
        else prev->next = np;
        prev = np;
        if (scanf("%d", &n) != 1) n = 0;
    }
    head = sortList(head);
    printf("Your list sorted: ");
    printList(head);
    printf("\n");
}
