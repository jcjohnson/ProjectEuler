#include <stdio.h>
#include <stdlib.h>

#define NUM_COINS 8

int vals[] = {1, 2, 5, 10, 20, 50, 100, 200};

int main() {
  int count = 0;
  int i, j, k, l, ii, jj, kk, ll, sum;

  for (i = 0; i <= 200; i++) {
    for (j = 0; j <= 100; j++) {
      for (k = 0; k <= 40; k++) {
        for (l = 0; l <= 20; l++) {
          for (ii = 0; ii <= 10; ii++) {
            for (jj = 0; jj <= 4; jj++) {
              for (kk = 0; kk <= 2; kk++) {
                for (ll = 0; ll <= 1; ll++) {
                  sum = 0;
                  sum += i * vals[0] + j * vals[1] + k * vals[2] + l * vals[3];
                  sum += ii * vals[4] + jj * vals[5] + kk * vals[6] + ll * vals[7];
                  
                  if (sum == 200) {
                    count++;
                  }
                }
              }
            }
          }
        }
      }
    }
  }

  printf("%d\n", count);

  return 0;
}
