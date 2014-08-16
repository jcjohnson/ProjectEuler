#include <stdio.h>

int main() {
    long dp[21][21];
    int i,j;
    for(i=0; i<21; i++) {
        for(j=0; j<21; j++) {
            if(i==0 || j==0) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
    }
    printf("%ld\n", dp[20][20]);
}
