#include <stdio.h>
#include <stdlib.h>

int * digitHist(int num) {
  int i;
  int *hist = (int *)malloc(10 * sizeof(int));
  for (i = 0; i < 10; i++) hist[i] = 0;

  while (num != 0) {
    hist[num % 10]++;
    num /= 10;
  }

  return hist;
}

int same(int *hist1, int *hist2) {
  int i;
  for (i = 0; i < 10; i++) {
    if (hist1[i] != hist2[i]) return 0;
  }
  return 1;
}

int main() {
  int x, k, works;
  int *hist1, *hist2;
  for (x = 1; 1; ++x) {
    hist1 = digitHist(x);
    works = 1;
    for (k = 2; works && k <= 6; ++k) {
      hist2 = digitHist(k * x);
      if (!same(hist1, hist2)) {
        works = 0;
      }
      free(hist2);
    }
    free(hist1);
    if (works) {
      printf("%d\n", x);
      return 0;
    }
  }
}
