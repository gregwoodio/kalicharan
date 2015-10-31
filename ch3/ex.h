/*
 * Header file for Data Structures in C by Noel Kalicharan
 * Chapter 3 exercises
 */
#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int num;
    struct node *next;
} Node, *NodePtr;

NodePtr mkNode(int);
int inAscendingOrder(NodePtr);
NodePtr reverse(NodePtr);
void printList(NodePtr);
NodePtr sortList(NodePtr);
void freeList(NodePtr);
NodePtr insertAt(NodePtr, int, int);
NodePtr toBinary(int);
int toDecimal(NodePtr);
