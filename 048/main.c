#include <stdio.h>
#include <stdlib.h>

long modPow(long a, long b, long m);
long timesPow(long a, long b, long m);

int main() {
  /*
  int i;
  long sum;
  long m = 10000000000;

  printf("%ld\n", m);

  for (i = 1; i <= 1000; i++) {
    long term = modPow(i, i, m);
    printf("%d^%d (mod %ld) = %ld\n", i, i, m, term);
  }
  */
  
  long m = 10000000000;
  printf("17^17 (mod %ld) = %ld\n", m, modPow(17, 17, m));

  return 0;
}

long modPow(long a, long b, long m) {
  int maxPow = 1, size = 0, i;
  long *powers, *pow2, ret;

  while (maxPow <= b) {
    maxPow *= 2;
    size++;
  }

  powers = (long *)malloc(size * sizeof(long));
  pow2 = (long *)malloc(size * sizeof(long));
  powers[0] = a % m;
  pow2[0] = 1;

  for (i = 1; i < size; i++) {
    powers[i] = timesPow(powers[i - 1], powers[i - 1], m);
    pow2[i] = 2 * pow2[i - 1];
    printf("pow2[%d] = %ld\tpowers[%d] = %ld\n", i, pow2[i], i, powers[i]);
  }

  ret = 1;
  for (i = size - 1; i >= 0; i--) {
    if (pow2[i] <= b) {
      b -= pow2[i];
      ret = (ret * powers[i]) % m;
    }
  }

  free(powers);
  free(pow2);

  return ret;
}

long timesPow(long a, long b, long m) {
  int maxPow = 1, size = 0, i;
  long *powers, *pow2, ret;

  while (maxPow <= b) {
    maxPow *= 2;
    size++;
  }

  powers = (long *)malloc(size * sizeof(long));
  pow2 = (long *)malloc(size * sizeof(long));
  powers[0] = a % m;

  for (i = 1; i < size; i++) {
    powers[i] = (powers[i - 1] + powers[i - 1]) % m;
    pow2[i] = 2 * pow2[i - 1];
  }

  ret = 0;
  for (i = size - 1; i >= 0; i--) {
    if (pow2[i] <= b) {
      b -= pow2[i];
      ret = (ret + powers[i]) % m;
    }
  }

  free(powers);
  free(pow2);

  return ret;
}
