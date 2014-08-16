#include <stdio.h>

#define LEN_10 7
#define LEN_2 21

int solve(int max) {
  int digits[LEN_10], bits[LEN_2];
  int numDigits, numBits;
  int i, num, sum;

  for (i = 0; i < LEN_10; i++) digits[i] = 0;
  for (i = 0; i < LEN_2; i++) bits[i] = 0;

  numDigits = 1;
  numBits = 1;
  sum = 0;
  num = 0;
  while (num < max) {
    int works = 1;

    for (i = 0; i < numDigits && works; i++) {
      if (digits[i] != digits[numDigits - 1 - i]) works = 0;
    }

    for (i = 0; i < numBits && works; i++) {
      if (bits[i] != bits[numBits - 1 - i]) works = 0;
    }

    if (works) {
      printf("%d\n", num);
      sum += num;
    }

    num++;

    // Increment digits
    i = 0;
    while (digits[i] == 9) {
      if (i == LEN_10 - 1) return sum;
      if (i + 1 == numDigits) numDigits++;
      digits[i] = 0;
      i++;
    }
    digits[i]++;

    // Increment bits
    i = 0;
    while (bits[i] == 1) {
      if (i == LEN_2 - 1) return sum;
      if (i + 1 == numBits) numBits++;
      bits[i] = 0;
      i++;
    }
    bits[i]++;
  }

  return sum;
}

int main() {
  int sum = solve(1000000);

  printf("sum = %d\n", sum);

  return 0;
}
