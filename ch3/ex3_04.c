/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 3 Exercise 4
 *
 * Exercise 4: Write a function to free all the nodes of a given linked 
 * list.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr mkNode(int);
void printList(NodePtr);
void freeList(NodePtr);

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

NodePtr mkNode(int n) {
    NodePtr np = (NodePtr) malloc(sizeof(Node));
    np->num = n;
    np->next = NULL;
    return np;
}

void printList(NodePtr np) {
    while (np != NULL) {
        printf("%d ", np->num);
        np = np->next;
    }
    return;
}

void freeList(NodePtr np) {
    NodePtr tmp;
    while (np != NULL) {
        tmp = np;
        np = np->next;
        free(tmp);
    }
    return;
}

