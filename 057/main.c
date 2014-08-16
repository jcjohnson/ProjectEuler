#include <stdio.h>

int numDigits(int n) {
  int count = 0;
  while (n != 0) {
    count++;
    n /= 10;
  }
  return count;
}

int gcd(int a, int b) {
  // return b == 0 ? a : gcd(b, a % b);
  return 1;
}

int main() {
  int n = 1;
  int d = 2;
  int i;
  int count = 0;

  for (i = 0; i < 1000  ; i++) {
    int nn = n + d;

    printf("%d / %d\n", nn, d);

    if (nn < 0 || d < 0) {
      printf("overflow\n");
      return 1;
    }

    if (numDigits(nn) > numDigits(d)) {
      count++;
    }

    nn = n;
    n = d;
    d = 2 * d + nn;
  }

  printf("%d\n", count);

  return 0;
}
