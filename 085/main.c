#include <stdio.h>

// The number of rectangles in a 1 x n strip is tri(n) = (n^2+n) / 2.
// The number of rectangles in an m x n strip is tri(n) * tri(m).

int abs(int n) {
  return n < 0 ? -n : n;
}

int main() {
  int target = 2000000;
  int bestP = 0;
  int bestNM = 0;
  int n = 1;
  int tn = 1;
  while (tn < 2 * target) {
    int m = 1;
    int tm = 1;
    int p = tm * tn;
    while (p < 2 * target) {
      if (abs(p - target) < abs(bestP - target)) {
        bestP = p;
        bestNM = n * m;
      }
      m++;
      tm += m;
      p = tm * tn;
    }
    n++;
    tn += n;
  }
  printf("%d\n", bestNM);
  return 0;
}
