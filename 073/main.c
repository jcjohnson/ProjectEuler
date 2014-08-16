#include <stdio.h>

#define MAX 12000

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int count = 0;
  int d, n;
  for (d = 1; d <= MAX; d++) {
    int low = d / 3 + 1;
    int high = d / 2;
    if (d % 2 == 0) high--;
    for (n = low; n <= high; n++) {
      if (gcd(n, d) == 1) count++;
    }
  }
  printf("%d\n", count);
  return 0;
}
