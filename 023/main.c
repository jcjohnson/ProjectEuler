#include <stdio.h>
#define MAX_VALUE 30000

int divisorSum(int n) {
    if(n == 1) return 0;
    int sum = 1;
    int i;
    for(i = 2; i*i < n; i++) {
        if(n % i == 0) sum += i + n/i;
    }
    if(i*i == n) sum += i;
    return sum;
}

int main() {
    int abundant[MAX_VALUE];
    int representable[MAX_VALUE];
    int i,j;
    for(i=1; i<MAX_VALUE; i++) representable[i] = 0;
    for(i=1; i<MAX_VALUE; i++) {
        if(divisorSum(i) > i) {
            abundant[i] = 1;
        } else {
            abundant[i] = 0;
        }
    }
    for(i=1; i<MAX_VALUE; i++) {
        for(j=1; j+i<MAX_VALUE; j++) {
            if(abundant[i] && abundant[j]) {
                representable[i+j] = 1;
            }
        }
    }
    int sum = 0;
    for(i=1; i<MAX_VALUE; i++) {
        if(!representable[i]) sum += i;
    }
    printf("%d\n", sum);
}
