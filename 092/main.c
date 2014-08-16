#include <stdio.h>

// Sum of squares of digits
int next(int num) {
  int sum = 0;
  while (num != 0) {
    int digit = num % 10;
    sum += digit * digit;
    num /= 10;
  }
  return sum;
}

int getTerminal(int num) {
  while (num != 1 && num != 89) {
    num = next(num);
  }
  return num;
}

#define MAX 10000000

int main() {
  int count = 0;
  int i;

  for (i = 1; i < MAX; i++) {
    if (getTerminal(i) == 89) {
      count++;
    }
  }

  printf("%d\n", count);

  return 0;
}
