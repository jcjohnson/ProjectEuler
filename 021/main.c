#include <stdio.h>
#include <math.h>

#define MAX_VALUE 10000

int divisorSum(int n) {
    int sum = 1;
    int i;
    for(i=2; i*i<n; i++) {
        if(n % i == 0) sum += i + n / i;
    }
    if(i*i == n) sum += i;
    return sum;
}   

int main() {
    int table[MAX_VALUE];
    int i, j;
    int sum = 0;
    for(i=2; i<MAX_VALUE; i++) {
        table[i] = divisorSum(i);
    }
    for(i=2; i<MAX_VALUE; i++) {
        int t = table[i];
        if(t < MAX_VALUE && t != i && table[t] == i) sum += i;
    }
    printf("%d\n", sum);
    return 0;
}
