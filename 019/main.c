#include <stdio.h>

int isLeapYear(int year) {
    if(year % 400 == 0) {
        return 1;
    } else if(year % 100 == 0) {
        return 0;
    } else if(year % 4 == 0) {
        return 1;
    } else {
        return 0;
    }
}

int monthLengths[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leapMonths[]   = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int monthLength(int month, int year) {
    if(isLeapYear(year)) return leapMonths[month];
    else return monthLengths[month];
}

int main() {
    int date = 1;
    int month = 0;
    int year = 1900;
    int day = 1;
    int count = 0;
    do {
        if(date == 1 && day == 0 && year >= 1901) count++;
        day = (day + 1) % 7;
        date++;
        if(date > monthLength(month, year) ) {
            date = 1;
            month++;
            if(month >= 12) {
                month = 0;
                year++;
            }
        }
    } while(date != 31 || month != 11 || year != 2000);
    printf("%d\n", count);
}
