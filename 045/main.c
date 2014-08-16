#include <stdio.h>
#include <math.h>

int main() {
  int ti = 1, pi = 1, hi = 1;
  long t = 1, p = 1, h = 1;

  int numFound = 0;
  while (numFound < 3) {
    if (t == p && p == h) {
      printf("%ld\n", t);
      numFound++;
    }

    if (t <= p && t <= h) {
      t += ti++ + 1;
    } else if (p <= t && p <= h) {
      p += 3 * pi++ + 1;
    } else if (h <= t && h <= p) {
      h += 4 * hi++ + 1;
    }
  }

  return 0;
}
