#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 100

char **readLines(FILE *fp, int *length) {
    char buf[MAX_LEN];
    int len = 0;
    while(!feof(fp)) {
        fgets(buf, MAX_LEN, fp);
        printf("Line %d is %s", len, buf);
        len++;
    }
    printf("there are %d lines in the file\n", len);
}

int main() {
    int length;
    FILE *fp = fopen("test.txt", "r");
    if(fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }
    readLines(fp, &length);
}
