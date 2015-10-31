/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 3 Exercise 8b
 * Write a function which, given a pointer to a string and a character, c, 
 * deletes all occurrences of c from the string. Return a pointer to the 
 * modified string.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char c;
    struct node *next;
} Node, *NodePtr;

NodePtr removeChar(NodePtr, char);
void replace(NodePtr, char, char);
NodePtr mkNode(char);
void printList(NodePtr);
void freeList(NodePtr);

int main() {

    char str[100], c;
    int i;
    NodePtr head = NULL, np, prev;

    printf("Please enter a string: \n");
    fgets(str, 99, stdin);
    printf("Which character to remove? \n");
    scanf("%c", &c);

    for (i = 0; str[i] != '\0' && i < 100; i++) {
        np = mkNode(str[i]);
        if (head == NULL) head = np;
        else prev->next = np;
        prev = np;
    }

    removeChar(head, c);
    printList(head);
    freeList(head);
    return 0;
}

NodePtr removeChar(NodePtr head, char c) {
    NodePtr prev = NULL, np = head;
    while (np != NULL) {
        if (np->c == c) {
            if (head == np) {
                head = np->next;
                free(np);
                np = head;
            } else {
                prev->next = np->next;
                free(np);
                np = prev->next;
            }
        } else {
            prev = np;
            np = np->next;
        }

    }
    return head;
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
