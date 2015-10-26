/* 
 * Data Structures in C by Noel Kalicharan
 * Chapter 3 Exercise 3
 *
 * Write a function which, given a pointer to a linked list of integers, 
 * returns 1 if the list is sorted in ascending order and 0 otherwise.
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr mkNode(int);
int inAscendingOrder(NodePtr);

int main() {
    
    NodePtr np, head = NULL, last;
    int n;
    printf("Enter numbers, or 0 to stop.");
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

NodePtr mkNode(int n) {
    NodePtr np = (NodePtr) malloc(sizeof(Node));
    np->num = n;
    np->next = NULL;
    return np;
}

int inAscendingOrder(NodePtr np) {
    int last = np->num;
    while (np != NULL) {
        if (last > np->num) {
            return 0;
        }
        np = np->next;
    }
    return 1;
}
