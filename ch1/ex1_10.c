/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 1 Exercise 10
 *
 * At a school's bazaar, activities were divided into 'stalls'. At the 
 * close of the bazaar, the manager of each stall submitted information
 * to the Principal consisting of the name of the stall, the income earned
 * and its expenses. Some sample data were:
 *  Games 2300.00 1000.00
 *  Sweets 900.00 1000.00
 * Using a structure to hold a stall's data, write a program to read the
 * data and print a report consisting of stall name and net income
 * (income-expenses), in order of decreasing net income (that is, with the
 * most profitable stall last). In addition, print the number of stalls,
 * the total profit or loss of the bazaar and the stalls which made the 
 * most profit. Assume that a line containing xxxxxx only ends the data.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 30

typedef struct stall {
    char *name;
    float income, expenses;
    struct stall* next;
} Stall;

Stall* makeStall(char*, float, float);
float getProfit(Stall*);
int countStalls(Stall*);
float totalProfit(Stall*);
void printList(Stall*);

int main() {
    
    char name[MAX_NAME], buffer[MAX_NAME + MAX_NAME];
    char *token;
    float income, expenses;
    Stall *top = NULL, *curr, *stall;
    printf("Enter stall name, income and expense, or xxxxxx to stop.\n");
    printf("Ex. Games 2300.00 1000.00\n");
    fgets(buffer, MAX_NAME * 2 - 1, stdin);
    token = strtok(buffer, " ");
    strcpy(name, token);

    while (strcmp(name, "xxxxxx\n") != 0) {
        token = strtok(NULL, " ");
        income = atof(token);
        token = strtok(NULL, " ");
        expenses = atof(token);

        curr = makeStall(name, income, expenses);

        if (top == NULL) {
            top = curr;
        } else if (getProfit(curr) > getProfit(top)) {
            curr->next = top;
            top = curr;
        } else {
            stall = top;
            while (stall != NULL && getProfit(curr) > getProfit(stall)) {
                stall = stall->next;
            }
            curr->next = stall->next;
            stall->next = curr;
        }

        fgets(buffer, MAX_NAME * 2 - 1, stdin);
        token = strtok(buffer, " ");
        strcpy(name, token);
    }

    printList(top);

    printf("\nNumber of stalls: %d\n", countStalls(top));
    printf("Most profitable stall: %s\n", top->name);
    printf("Total profit: $%.2f\n", totalProfit(top));
    return;
}

Stall* makeStall(char *name, float in, float ex) {
    Stall* stall = (Stall*)malloc(sizeof(Stall));
    stall->name = (char*)malloc(sizeof(char) * MAX_NAME);
    strcpy(stall->name, name);
    stall->income = in;
    stall->expenses = ex;
    stall->next = NULL;
    return stall;
}

float getProfit(Stall *stall) {
    return stall->income - stall->expenses;
}

int countStalls(Stall *stall) {
    int num = 0;
    while (stall != NULL) {
        num++;
        stall = stall->next;
    }
    return num;
}

float totalProfit(Stall *stall) {
    float profit;
    while (stall != NULL) {
        profit += getProfit(stall);
        stall = stall->next;
    }
    return profit;
}

void printList(Stall *stall) {
    printf("%-30s Profit\n", "Stall");
    while (stall != NULL) {
        printf("%-30s $%.2f\n", stall->name, getProfit(stall));
        stall = stall->next;
    }
}
