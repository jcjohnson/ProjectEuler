#include <stdio.h>

#define MAX 1000

int cycleLength(int d) {
  int r, i;
  int remainders[MAX];

  for (i = 0; i < MAX; i++) {
    remainders[i] = 0;
  }

  i = 0;
  r = 1;
  while (1) {
    if (remainders[r]) {
      return i - remainders[r];
    }

    remainders[r] = i;
    i++;

    r *= 10;
    r %= d;
  }
}

int main() {
  int d, len, max, longest;

  max = 0;
  for (d = 1; d < MAX; d++) {
    len = cycleLength(d);
    if (len > max) {
      max = len;
      longest = d;
    }
  }

  printf("%d\n", longest);

  return 0;
}
