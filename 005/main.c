#include <stdio.h>

int works(int n) {
  int i;
  for (i = 2; i <= 20; i++) {
    if (n % i != 0) return 0;
  }
  return 1;
}

int main() {
  int n = 1;
  while (!works(n)) {
    n++;
  }
  printf("%d\n", n);
  return 0;
}
