/*
 * Data Structures in C by Noel Kalicharan
 * Chapter 1 Exercise 8
 *
 * A length, specified in metres and centimeters, is represented by two
 * integers. For example, the length 3m 75cm is represented by 3 75. Using
 * a structure to represent a length, write functions to compare, add and
 * subtract two lengths.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct length {
    int meter;
    int centimeter;
} Length;

Length* makeLength(int, int);
int compareLength(Length*, Length*);
Length* addLength(Length*, Length*);
Length* subtractLength(Length*, Length*);

int main() {
    int x, y;
    Length *l1, *l2, *sum;

    printf("Enter the first length (xx yy): ");
    scanf("%d %d", &x, &y);
    l1 = makeLength(x, y);

    printf("Enter the second length (xx yy): ");
    scanf("%d %d", &x, &y);
    l2 = makeLength(x, y);

    printf("Compare lengths: %d\n", compareLength(l1, l2));
    
    sum = addLength(l1, l2);
    printf("Length 1 + Length 2 = %d %d\n", sum->meter, sum->centimeter);

    sum = subtractLength(l1, l2);
    printf("Length 1 - Length 2 = %d %d\n", sum->meter, sum->centimeter);
}

Length* makeLength(int m, int cm) {
    Length* l = (Length*)malloc(sizeof(Length));
    l->meter=m;
    l->centimeter=cm;
    return l;
}

/*
 * Return 1 if the second number is bigger, -1 for first number is bigger,
 * 0 for the same.
 */
int compareLength(Length *l1, Length *l2) {
    if (l1->meter > l2->meter)
        return -1;
    else  if (l1->meter < l2->meter)
        return 1;
    else if (l1->centimeter > l2->centimeter)
        return -1;
    else if (l1->centimeter < l2->centimeter)
        return 1;
    else
        return 0;
}

Length* addLength(Length *l1, Length *l2) { 
    int m = (l1->meter * 100 + l1->centimeter) + (l2->meter * 100 + l2->centimeter);
    Length* sum = makeLength(m/100, m%100);
    return sum;
}

Length* subtractLength(Length *l1, Length *l2) {
    int m = (l1->meter * 100 + l1->centimeter) - (l2->meter * 100 + l2->centimeter);
    Length* sum = makeLength(m/100, m%100);
    return sum;
}
