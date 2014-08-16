#include <stdio.h>

const long N = 1000000000000;
// const long N = 100000000000000;

int main() {
  long z = 1;
  long t = 1;
  long zz = 17;
  long tt = 1;
  while (1) {
    // long zz = 8 * z * z + 8 * z + 1;
    // long tt = t * t;
    if (zz < 0 || tt < 0) {
      printf("OVERFLOW\n");
      break;
    }
    if (zz == tt) {
      long x = z + 1;
      long y = (1 + t) / 2;
      printf("x = %ld\ty = %ld\n", x, y);
      if (y > N) break;
    }
    if (zz < tt) {
      z++;
      zz += 16 * z;
    } else {
      tt += 4 * t + 4;
      t += 2;
    }
  }
  return 0;
}

/*
x = 3	y = 4
x = 15	y = 21
x = 85	y = 120
x = 493	y = 697
x = 2871	y = 4060
x = 16731	y = 23661
x = 97513	y = 137904
x = 568345	y = 803761
x = 3312555	y = 4684660
x = 19306983	y = 27304197
x = 112529341	y = 159140520
x = 655869061	y = 927538921
*/
