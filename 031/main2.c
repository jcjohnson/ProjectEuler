#include <stdio.h>

#define NUM_COINS 8
#define VAL 200

int vals[] = {1, 2, 5, 10, 20, 50, 100, 200};

int main() {
  int w = VAL + 1;
  int h = NUM_COINS;
  int ways[NUM_COINS * (VAL + 1)];
  int i, j, c;

  // Zero that bitch out
  for (i = 0; i < NUM_COINS * VAL; i++) ways[i] = 0;
  
  // Initial condition
  for (i = 0; i < VAL + 1; i++) ways[i] = 1;

  for (c = 1; c < NUM_COINS; c++) {
    for (i = 0; i <= VAL; i++) {
      for (j = i; j >= 0; j -= vals[c]) {
        ways[c * w + i] += ways[(c - 1) * w + j];
      }
    }
  }

  printf("%d\n", ways[(h - 1) * w + (w - 1)]);
      
  return 0;
}
