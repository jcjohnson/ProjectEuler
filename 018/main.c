#include <stdio.h>

#define NUM_ROWS 15

int main() {
    FILE *fp = fopen("triangle.txt", "r");
    int triangle[NUM_ROWS][NUM_ROWS];
    int i,j;
    for(i=0; i<NUM_ROWS; i++) {
        for(j=0; j<=i; j++) {
            triangle[i][j] = 10*(fgetc(fp)-'0');
            triangle[i][j] += fgetc(fp) - '0';
            fgetc(fp);
        }
    }
    for(i=NUM_ROWS-2; i>=0; i--) {
        for(j=0; j<=i; j++) {
            if(triangle[i+1][j] > triangle[i+1][j+1]) {
                triangle[i][j] += triangle[i+1][j];
            } else {
                triangle[i][j] += triangle[i+1][j+1];
            }
        }
    }
    printf("%d\n", triangle[0][0]);
    fclose(fp);
    return 0;
}
