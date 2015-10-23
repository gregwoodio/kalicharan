/*
 * A time in 24-hour clock format is represented by two numbers: eg. 16 45
 * means the time 16:45, that is 4:45pm. Using a structure to represent the
 * time, write a function which given two structures, t1 and t2, returns
 * the number of minutes from t1 to t2. For example, if the two given times
 * are 16 45 and 23 25, your function should return 400.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct time {
    char hour;
    char min;
} Time;

int compareTime(Time*, Time*);

int main() {
    Time *t1, *t2;
    t1 = (Time*)malloc(sizeof(Time));
    t2 = (Time*)malloc(sizeof(Time));
    printf("Enter first time (format is hh mm): ");
    scanf("%d %d", &(t1->hour), &(t1->min));
    printf("Enter second time (format is hh mm): ");
    scanf("%d %d", &(t2->hour), &(t2->min));
    printf("Difference: %d\n", compareTime(t1, t2));
}

int compareTime(Time* t1, Time* t2) {
    int time;
    if (t2->hour < t1->hour) {
        time = (t2->hour + 24 - t1->hour) * 60;
    } else {
        time = (t2->hour - t1->hour) * 60;
    }
    time += t2->min - t1->min;
    return time;
}
