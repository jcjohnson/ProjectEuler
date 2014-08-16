#include <assert.h>
#include <stdio.h>

#define MAX 100

int main() {
  int p[MAX + 1][MAX + 1];
  int n, k;

  for (n = 1; n <= MAX; n++) {
    for (k = MAX; k > 0; k--) {
      if (k > n) {
        p[n][k] = 0;
      } else if (n == k) {
        p[n][k] = 1;
      } else {
        p[n][k] = p[n][k + 1] + p[n - k][k];
      }
    }
  }

  printf("%d\n", p[MAX][1] - 1);

  return 0;
}
