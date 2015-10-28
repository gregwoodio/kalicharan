/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 3 exercise 3
 *
 * Write a function to sort a linked list as follows:
 * 1. Find the largest value in the list.
 * 2. Delete it from its position and insert it at the head of the list.
 * 3. Starting from what is now the second element, repeat (a) and (b).
 * 4. Starting from what is now the third element, repeat (a) and (b).
 * Continue until sorted.
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int n;
    struct node *next;
} Node, *NodePtr;

NodePtr mkNode(int);
NodePtr sortList(NodePtr);
void printList(NodePtr);

int main() {
       
    NodePtr head = NULL, np, prev;
    int n;

    printf("Enter numbers, or 0 to stop.");
    if (scanf("%d", &n) != 1) n = 0;
    while (n != 0) {
        np = mkNode(n);
        if (head == NULL) head = np;
        else prev->next = np;
        prev = np;
        if (scanf("%d", &n) != 1) n = 0;
    }
    head = sortList(head);
    printList(head);
    printf("\n");
}

NodePtr mkNode(int n) {
    NodePtr np = (NodePtr) malloc(sizeof(Node));
    np->n = n;
    np->next = NULL;
    return np;
}

void printList(NodePtr head) {
    NodePtr np = head;
    while (np != NULL) {
        printf("%d ", np->n);
        np = np->next;
    }
    return;
}

NodePtr sortList(NodePtr head) {
    NodePtr beforeBiggest = NULL, biggest = NULL, prev = NULL, np = head;
    int big = 0;

    /* if there are no more nodes after this one, just return head */
    if (head->next == NULL) {
        return head;
    }

    /* find biggest */
    while (np != NULL) {
        if (np->n > big) {
            big = np->n;
            biggest = np;

            if (prev != NULL)
                beforeBiggest = prev;
        }
        prev = np;
        np = np->next;
    }

    /* move biggest to front */
    if (beforeBiggest != NULL)
        beforeBiggest->next = biggest->next;
    if (biggest != head)
        biggest->next = head;
    head = biggest;

    /* Recursively sort, starting at next node */
    head->next = sortList(head->next);
    return head;
}
