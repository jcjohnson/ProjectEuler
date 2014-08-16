#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int numDigits(long num) {
  int digits = 0;
  while (num != 0) {
    num /= 10;
    digits++;
  }
  return digits;
}

long intpow(long a, long b) {
  int i;
  long p = 1;
  for (i = 0; i < b; i++) {
    p *= a;
  }
  
  if (p < 0) {
    printf("%ld^%ld = %ld is an overflow\n", a, b, p);
    exit(1);
  }
  return p;
}

int main() {
  int count = 0;
  int a, b, d;

  for (b = 1; b <= 18; b++) {
    a = 1;
    d = numDigits(intpow(a, b));
    while (d <= b) {
      if (d == b) {
        printf("%d^%d has %d digits\n", a, b, d);        
        count++;
      }
      a++;
      d = numDigits(intpow(a, b));
    }
  }

  printf("%d\n", count);
}
