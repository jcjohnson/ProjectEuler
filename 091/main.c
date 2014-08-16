#include <stdio.h>

const int MAX = 50;

int main() {
  int x1, x2, y1, y2;
  int count = 0;
  for (x1 = 0; x1 <= MAX; x1++) {
    for (x2 = 0; x2 <= MAX; x2++) {
      for (y1 = 0; y1 <= MAX; y1++) {
        for (y2 = 0; y2 <= MAX; y2++) {
          int aa = x1 * x1 + y1 * y1;
          int bb = x2 * x2 + y2 * y2;
          int cc = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
          if ((aa > 0 && bb > 0 && cc > 0) && 
              (aa + bb == cc || aa + cc == bb || bb + cc == aa)) {
            count++;
          }
        }
      }
    }
  }
  printf("%d\n", count / 2);
}
