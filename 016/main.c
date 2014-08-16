#include <stdio.h>
#include <stdlib.h>

#define SIZE 305

int main() {
    unsigned char digits[SIZE];
    int i, j;
    for(i=0; i<SIZE; i++) digits[i] = 0;
    digits[0] = 1;
    for(i=0; i<1000; i++) {
        int carry = 0;
        for(j=0; j<SIZE; j++) {
            int val = digits[j] + digits[j] + carry;
            digits[j] = val % 10;
            carry = val / 10;
        }
    }
    int sum = 0;
    for(i=0; i<SIZE; i++) sum += digits[i];
    printf("%d\n", sum);
}
