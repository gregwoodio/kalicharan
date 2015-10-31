/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 3 Exercise 8d
 *
 * Write a function which creates a new list consisting of letters
 * only in the given list, all converted to lowercase and stored
 * in alphabetical order. Return a pointer to the new list.
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
    char c;
    struct node *next;
} Node, *NodePtr;

void stringToUpper(NodePtr);
void stringToLower(NodePtr);
NodePtr removeChar(NodePtr, char);
void replace(NodePtr, char, char);
NodePtr mkNode(char);
void printList(NodePtr);
void freeList(NodePtr);
NodePtr alphabeticalSort(NodePtr);

int main() {

    char str[100];
    int i;
    NodePtr head = NULL, np, prev, sorted;

    printf("Please enter a string: \n");
    fgets(str, 99, stdin);

    for (i = 0; str[i] != '\0' && i < 100; i++) {
        if (isalnum(str[i])) {
            np = mkNode(str[i]);
            if (head == NULL) head = np;
            else prev->next = np;
            prev = np;
        }
    }

    stringToLower(head);
    printList(head);
    sorted = alphabeticalSort(head);
    printf("\nSorted: ");
    printList(head);
    freeList(head);
    freeList(sorted);

    printf("\n");
    return 0;
}

NodePtr alphabeticalSort(NodePtr head) {
    NodePtr beforeFirst = NULL, first = NULL, prev = NULL, np = head;
    char firstChar = '~'; /*~ is an arbitrary high char value */

    if (head->next == NULL) {
        return head;
    }

    while (np != NULL) {
        if (np->c < firstChar) {
            firstChar = np->c;
            first = np;
            if (prev != NULL)
                beforeFirst = prev;
        }
        prev = np;
        np = np->next;
    }

    if (beforeFirst != NULL)
        beforeFirst->next = first->next;
    if (first != head)
        first->next = head;
    head = first;

    head->next = alphabeticalSort(head->next);
    return head;
}

void stringToLower(NodePtr head) {
    while (head != NULL) {
        if (isupper(head->c)) {
            head->c = (head->c) + 32;
        }
        head = head->next;
    }
    return;
}

void stringToUpper(NodePtr head) {
    while (head != NULL) {
        if (islower(head->c)) {
            head->c = (head->c) - 32;
        }
        head = head->next;
    }
    return;
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
