#include <stdio.h>

#define LEN 7

int printDigits(int maxDigits, int *facts) {
  int i, num, numDigits, digitSum, sum;
  int digits[maxDigits];
  for (i = 0; i < maxDigits; i++) digits[i] = 0;

  numDigits = 1;
  num = 0;
  sum = 0;
  while (1) {
    if (num > 9) {
      digitSum = 0;
      for (i = 0; i < numDigits; i++) {
        digitSum += facts[digits[i]];
      }
      if (digitSum == num) {
        printf("%d\n", num);
        sum += num;
      }
    }

    // Increment
    num++;
    i = 0;
    while (digits[i] == 9) {
      if (i == maxDigits - 1) return sum;
      if (i + 1 == numDigits) numDigits++;
      digits[i] = 0;
      i++;
    }
    digits[i]++;
  }
}

int main() {
  int facts[10], sum, i;

  facts[0] = 1;
  for (i = 1; i < 10; i++) {
    facts[i] = i * facts[i - 1];
  }

  sum = printDigits(7, facts);
  printf("sum = %d\n", sum);

  return 0;
}
