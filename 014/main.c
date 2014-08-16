#include <stdio.h>

int chainLength(long n) {
    int len = 1;
    while(n != 1) {
        n = (n % 2 == 0 ? n/2 : 3*n + 1);
        len++;
    }
    return len;
}

int main() {
    int maxLength = 0;
    int maxNum = 0;
    int i;
    for(i=1; i<1000000; i++) {
        int len = chainLength(i);
        printf("%d %d\n", i, len);
        if(len > maxLength) {
            maxLength = len;
            maxNum = i;
        }
    }
    printf("The max is: %d\n", maxNum);
}
