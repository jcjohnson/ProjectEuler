#include <stdio.h>

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  int n, d;
  int d1, d10, n1, n10;
  int pn = 1;
  int pd = 1;

  for (d = 10; d < 100; d++) {
    d1 = d % 10;
    d10 = d / 10;
    for (n = 10; n < d; n++) {
      n1 = n % 10;
      n10 = n / 10;

      // Turns out this is the only case that matters.
      if (n1 == d10 && n * d1 == d * n10) {
        printf("%d/%d = %d/%d\n", n, d, n10, d1);
        pn *= n10;
        pd *= d1;
      }

      if (n1 == d1 && n1 != 0 && n * d10 == d * n10) {
        printf("%d/%d = %d/%d\n", n, d, n10, d10);
        pn *= n10;
        pd *= d10;
      }

      if (n10 == d1 && n * d10 == d * n1) {
        printf("%d/%d = %d/%d", n, d, n1, d10);
        pn *= n1;
        pd *= d10;
      }

      if (n10 == d10 && n * d1 == d * n1) {
        printf("%d/%d = %d/%d\n", n, d, n1, d1);
        pn *= n1;
        pd *= d1;
      }
    }
  }

  printf("product = %d/%d\n", pn, pd);
  printf("reduced denominator = %d\n", pd / gcd(pn, pd));

  return 0;
}
