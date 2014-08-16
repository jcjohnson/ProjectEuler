#include <stdio.h>

int main() {
  const int sum = 1000;
  int a, b, c;
  for (a = 1; a < 1000; a++) {
    for (b = a + 1; b < sum - a - b; b++) {
      c = sum - a - b;
      if (a * a + b * b == c * c) {
        printf("%d\n", a * b * c);
        return 0;
      }
    }
  }
  return 0;
}
