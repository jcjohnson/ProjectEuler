#include <stdio.h>
#include <stdlib.h>

#define MAX 10000000

int next(int num) {
  int sum = 0;
  while (num != 0) {
    int digit = num % 10;
    sum += digit * digit;
    num /= 10;
  }
  return sum;
}

int main() {
  int count = 0;
  int i, j;

  int *terminal = (int *)malloc(MAX * sizeof(int));

  for (i = 1; i < MAX; i++) {
    int j = i;
    while (j != 1 && j != 89) {
      if (j < i) {
        j = terminal[j];
      } else {
        j = next(j);
      }
    }
    if (j == 89) count++;
    terminal[i] = j;
  }

  printf("%d\n", count);

  free(terminal);

  return 0;
}
