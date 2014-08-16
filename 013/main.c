#include <stdio.h>
#include <stdlib.h>

int main() {
    int numbers[100][50];
    int sum[50];
    FILE *fp = fopen("numbers.txt", "r");
    int i,j, carry, small_sum;
    for(i=0; i<100; i++) {
        for(j=0; j<50; j++) {
            numbers[i][j] = fgetc(fp) - '0';
        }
        fgetc(fp);
    }
    carry = 0;
    for(j=49; j>=0; j--) {
        small_sum = carry;
        for(i=0; i<100; i++) {
            small_sum += numbers[i][j];
        }
        sum[j] = small_sum % 10;
        carry = small_sum / 10;
    }
    printf("%d", carry);
    for(i=0; i<8; i++) printf("%d",sum[i]);
    printf("\n");
    fclose(fp);
    return 0;
}
