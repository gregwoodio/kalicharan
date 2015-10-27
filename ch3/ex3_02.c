/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 3 Exercise 2
 *
 * Exercise 2: Write code to reverse the nodes of a linked list by 
 * manipulating the pointer fields only. No new nodes must be created.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr mkNode(int);
void printList(NodePtr);
NodePtr reverse(NodePtr);

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

NodePtr mkNode(int n) {
    NodePtr np = (NodePtr) malloc(sizeof(Node));
    np->num = n;
    np->next = NULL;
    return np;
}

NodePtr reverse(NodePtr head) {
    NodePtr prev = NULL, np = head;
    while (head != NULL) {
        np = head;
        head = head->next;
        np->next = prev;
        prev = np;
    }
    return np;
}

void printList(NodePtr head) {
    NodePtr np = head;
    while (np != NULL) {
        printf("%d ", np->num);
        np = np->next;
    }
    return;
}
