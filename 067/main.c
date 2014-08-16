#include <stdio.h>

int max(int a, int b) {
  return a > b ? a : b;
}

int main() {
  int line, i, num, best;

  int bestSum[100];
  int temp[100];

  for (line = 1; line <= 100; line++) {
    for (i = 0; i < line; i++) {
      scanf("%d", &num);
      if (line == 0) {
        temp[i] = num;
      } else if (i == 0) {
        temp[i] = bestSum[i] + num;
      } else if (i == line - 1) {
        temp[i] = bestSum[i - 1] + num;
      } else {
        temp[i] = max(bestSum[i - 1], bestSum[i]) + num;
      }
    }
    for (i = 0; i < line; i++) {
      bestSum[i] = temp[i];
    }
  }

  best = 0;
  for (i = 0; i < 100; i++) {
    best = bestSum[i] > best ? bestSum[i] : best;
  }

  printf("%d\n", best);

  return 0;
}
