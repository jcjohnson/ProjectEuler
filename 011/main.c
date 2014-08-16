#include <stdio.h>
#include <stdlib.h>

int readNum(FILE *fp) {
    int c1 = fgetc(fp);
    int c2 = fgetc(fp);
    int num = 10 * (c1 - '0') + (c2 - '0');
    fgetc(fp);
    return num;
}

int main() {
    int grid[20][20];
    int i,j,k;
    int num;
    FILE *fp = fopen("grid.txt", "r");
    if(fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    for(i=0; i<20; i++) {
        for(j=0; j<20; j++) {
            grid[i][j] = readNum(fp);
            printf("%2d ", grid[i][j]);
        }
        printf("\n");
    }
    int max = 0;
    int bestI = 0;
    int bestJ = 0;
    char mode = ' ';
    // check horizontal lines
    for(i=0; i<20; i++) {
        for(j=0; j<17; j++) {
            num = 1;
            for(k=0; k<4; k++) {
                num *= grid[i][j+k];
            }
            if(num > max) {
                max = num;
                bestI = i;
                bestJ = j;
                mode = 'h';
            }
        }
    }
    // check vertical lines
    for(i=0; i<17; i++) {
        for(j=0; j<20; j++) {
            num = 1;
            for(k=0; k<4; k++) {
                num *= grid[i+k][j];
            }
            if(num > max) {
                max = num;
                bestI = i;
                bestJ = j;
                mode = 'v';
            }
        }
    }
    // check for diagonal lines down
    for(i=0; i<17; i++) {
        for(j=0; j<17; j++) {
            num = 1;
            for(k=0; k<4; k++) {
                num *= grid[i+k][j+k];
            }
            if(num > max) {
                max = num;
                bestI = i;
                bestJ = j;
                mode = 'd';
            }
        }
    }
    // check for diagonal lines up
    for(i=3; i<20; i++) {
        for(j=0; j<17; j++) {
            num = 1;
            for(k=0; k<4; k++) {
                num *= grid[i-k][j+k];
            }
            if(num > max) {
                max = num;
                bestI = i;
                bestJ = j;
                mode = 'p';
            }
        }
    }
    printf("%d\n", max);
    printf("(%d, %d), %s\n", bestI, bestJ, &mode);
}
