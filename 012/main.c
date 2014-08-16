#include <stdio.h>
#include <math.h>

// The number of divisors of a number n
int numDivisors(int n) {
    int num = 2;
    int i;
    for(i = 2; i<sqrt(n); i++) {
        if(n % i == 0) num += 2;
    }
    if(num == ( (int)sqrt(n) ) * ( (int)sqrt(n) ) ) num++;
    return num;
}

// The number of divisors of the nth triangular number
// This relies on the fact that tri(n) = n(n+1)/2 and 
// that (n, n+1) = 1
int numTriDivisors(int n) {
    if(n % 2 == 0) {
        return numDivisors(n/2) * numDivisors(n+1);
    } else {
        return numDivisors(n) * numDivisors((n+1)/2);
    }
}

int main() {
    int i = 1;
    int t = 1;
    int num;
    while(1) {
        num = numTriDivisors(i);
        //printf("%d %d %d\n", i, t, num);
        if(num > 500) {
            printf("%d\n", (i*i+i)/2);
            return 0;
        }
        i++;
    }
}
