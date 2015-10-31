#include "ex.h"

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

NodePtr sortList(NodePtr head) {
    NodePtr beforeBiggest = NULL, biggest = NULL, prev = NULL, np = head;
    int big = 0;

    /* If there are no more nodes after this one, just return head */
    if (head->next == NULL) {
        return head;
    }

    /* find biggest */
    while (np != NULL) {
        if (np->num > big) {
            big = np->num;
            biggest = np;
            /*beforeBiggest = prev;*/
            if (prev != NULL)
                beforeBiggest = prev;
        }
        prev = np;
        np = np->next;
    }

    /*move biggest to front */
    if (beforeBiggest != NULL) 
        beforeBiggest->next = biggest->next; 
    if (biggest != head)        
        biggest->next = head;
    head = biggest;

    /* Recursively sort, starting at the next node */
    head->next = sortList(head->next);
    return head;
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

NodePtr insertAt(NodePtr head, int n, int j) {
    /* Insert n at jth element, return head of list */
    NodePtr prev, np = head;
    NodePtr nodeN = mkNode(n);
    if (j == 0) {
        /* nodeN is the new head */
        nodeN->next = head;
        return nodeN;
    }
    while (np != NULL && j > 0) {
        prev = np;
        np = np->next;
        j--;
    }
    prev->next = nodeN;
    nodeN->next = np;
    return head;
}

NodePtr toBinary(int n) {
    NodePtr np = mkNode(n % 2);

    if (n <= 1) {
        return np;
    }

    np->next = toBinary(n / 2);
    return np;
}

int toDecimal(NodePtr np) {
    int sum = 0, multiplier = 1;
    while (np != NULL) {
        sum += multiplier * np->num;
        multiplier *= 2;
        np = np->next;
    }
    return sum;
}
