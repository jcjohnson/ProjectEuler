#include <stdio.h>

#include "frac.h"

int getA(int k) {
  if (k == 0) return 2;
  if (k % 3 == 2) return 2 * ((k + 1) / 3);
  return 1;
}

void getConvergent(int n, frac *result) {
  int k;
  frac *f = result;
  f->num = getA(n);
  f->den = 1;

  for (k = n - 1; k >= 0; k--) {
    frac_print(f);
    frac_inverse(f, f);
    frac_add_long(f, getA(k), f);
  }
  frac_print(f);
}

int digitSum(int n) {
  int sum = 0;
  while (n != 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
  frac f;
  getConvergent(99, &f);
  printf("%d\n", digitSum(f.num));
  return 0;
}
