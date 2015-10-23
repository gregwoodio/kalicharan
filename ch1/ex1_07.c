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

}


int compareTime(Time* t1, Time* t2) {
    int time;
    if (t2->hour < t1->hour) {
        time = (t2->hour + 24 - t1->hour) * 60;
    } else {
        time = (t2->hour - t1->hour) * 60;
    }
}
