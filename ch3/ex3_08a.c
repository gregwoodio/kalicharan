/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 3 Exercise 8a
 *
 * The characters of a string are held in a linked list, one character per 
 * node. Write a function which, given a pointer to a string and two 
 * characters, c1 and c2, replaces all occurences of c1 with c2.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char c;
    struct node *next;
} Node, *NodePtr;

void replace(NodePtr, char, char);
NodePtr mkNode(char);
void printList(NodePtr);
void freeList(NodePtr);

int main() {

    char str[100], c1, c2;
    int i;
    NodePtr head = NULL, np, prev;

    printf("Please enter a string: \n");
    fgets(str, 99, stdin);
    printf("Which character to replace? \n");
    scanf("%c", &c1);
    printf("Replace with what character? \n");
    scanf("%c"); /*gets the newline character */
    scanf("%c", &c2);

    for (i = 0; str[i] != '\0' && i < 100; i++) {
        np = mkNode(str[i]);
        if (head == NULL) head = np;
        else prev->next = np;
        prev = np;
    }

    replace(head, c1, c2);
    printList(head);
    freeList(head);
    return 0;
}

void replace(NodePtr head, char c1, char c2) {
    while (head != NULL) {
        if (head->c == c1) {
            head->c = c2;
        }
        head = head->next;
    }
    return;
}

NodePtr mkNode(char c) {
    NodePtr np;
    np = (NodePtr) malloc(sizeof(Node));
    np->c = c;
    np->next = NULL;
    return np;
}

void printList(NodePtr head) {
    while (head != NULL) {
        printf("%c", head->c);
        head = head->next;
    }
    return;
}

void freeList(NodePtr head) {
    NodePtr tmp;
    while (head != NULL) {
        tmp = head;
        head = head->next;
        free(tmp);
    }
    return;
}
