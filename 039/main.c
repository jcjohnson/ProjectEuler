#include <stdio.h>

int numSolutions(int p);

int main() {
  int p, max, bestP;

  max = 0;
  bestP = 0;

  for (p = 1; p <= 1000; p++) {
    int sol = numSolutions(p);
    if (sol > max) {
      max = sol;
      bestP = p;
    }
  }

  printf("%d\n", bestP);

  return 0;
}

int numSolutions(int p) {
  int a, b, count;

  count = 0;
  for (a = 1; a < p / 2; a++) {
    for (b = 1; b <= a; b++) {
      int c = p - a - b;
      if (a * a + b * b == c * c) {
        count++;
      }
    }
  }

  return count;
}
