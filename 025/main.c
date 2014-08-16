#include <stdio.h>
#define MAX_DIGITS 1000

void printNum(unsigned char *num) {
    int i;
    for(i=MAX_DIGITS-1; i>=0; i--) {
        printf("%d", num[i]);
    }
    printf("\n");
}

int main() {
    unsigned char fib1[MAX_DIGITS];
    unsigned char fib2[MAX_DIGITS];
    unsigned char fib3[MAX_DIGITS];
    int i;
    for(i=0; i<MAX_DIGITS; i++) {
        fib1[i] = 0;
        fib2[i] = 0;
        fib3[i] = 0;
    }
    fib2[0] = 1;
    int index = 1; // the index of fib2
    while(fib2[MAX_DIGITS-1] == 0) {
        //printf("%d  ", index);
        //printNum(fib2);
        // Add fib1 and fib2 to produce fib3
        unsigned char carry = 0;
        for(i=0; i<MAX_DIGITS; i++) {
            unsigned char val = fib1[i] + fib2[i] + carry;
            fib3[i] = val % 10;
            carry = val / 10;
        }
        // Copy fib3 -> fib2, fib2 -> fib1
        for(i=0; i<MAX_DIGITS; i++) {
            fib1[i] = fib2[i];
            fib2[i] = fib3[i];
        }
        index++;
    }
    // Now fib2 has the answer; print its index
    printf("%d\n", index);
}
