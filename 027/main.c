#include <stdio.h>

int isPrime(int n) {
  int i;

  if (n <= 1) return 0;
  if (n == 2) return 1;

  for (i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }

  return 1;
}

int evalQuad(int a, int b, int n) {
  return n * n + a * n + b;
}

int consecutivePrimes(int a, int b) {
  int n = 0;
  int num = 0;
  
  while (isPrime(evalQuad(a, b, n))) {
    n++;
    num++;
  }

  return num;
}

int main() {
  int bestA, bestB;
  int a, b, num;
  int max = 0;

  for (a = -999; a <= 999; a++) {
    for (b = -999; b <= 999; b++) {
      num = consecutivePrimes(a, b);
      if (num > max) {
        max = num;
        bestA = a;
        bestB = b;
        printf("a = %d, b = %d gives %d consecutive primes\n", a, b, max);
      }
    }
  }

  printf("%d\n", bestA * bestB);
}
