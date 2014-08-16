#include <stdio.h>

int main() {
  int f1 = 1;
  int f2 = 2;
  int sum = 0;
  int temp;

  while (f2 < 4000000) {
    if (f2 % 2 == 0) sum += f2;
    temp = f1 + f2;
    f1 = f2;
    f2 = temp;
  }

  printf("%d\n", sum);

  return 0;
}
