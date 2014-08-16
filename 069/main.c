// This is really slow but probably correct; however I actually solved the
// problem logically rather than programatically.

#include <stdio.h>

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int phi(int n) {
  int count = 1;
  int i;
  for (i = 2; i < n; i++) {
    if (gcd(n, i) == 1) count++;
  }
  return count;
}

int fracLess(int n1, int d1, int n2, int d2) {
  return n1 * d2 < n2 * d1;
}

#define MAX 5000

int main() {
  int maxN = 0;
  int maxP = 1;
  int n;
  for (n = 1; n <= MAX; n++) {
    int p = phi(n);
    // printf("%d\t%d\n", n, p);
    if (fracLess(maxN, maxP, n, p)) {
      maxN = n;
      maxP = p;
    }
  }
  printf("%d\n", maxN);
}
