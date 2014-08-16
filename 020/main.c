#include <stdio.h>

#define SIZE 200

int main() {
    unsigned char num[SIZE];
    int i, n;
    for(i=1; i<SIZE; i++) num[i] = 0;
    num[0] = 1;
    for(n=2; n<=100; n++) {
        int carry = 0;
        for(i=0; i<SIZE; i++) {
            int val = n * num[i] + carry;
            num[i] = val % 10;
            carry = val / 10;
        }
    }
    int count = 0;
    for(i=0; i<SIZE; i++) {
        count += num[i];
    }
    printf("%d\n", count);
}
