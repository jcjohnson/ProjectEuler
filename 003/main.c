#include <stdio.h>

int isPrime(long n) {
  long i;

  if (n == 2) return 1;

  for (i = 2; i * i <= n; i++) {
    if (n % i == 0) return 0;
  }

  return 1;
}

int largestPrimeFactor(long n) {
  long i, largest;

  largest = 1;

  for (i = 2; i <= 2 * n; i++) {
    if (n % i == 0 && isPrime(i)) {
      n /= i;
      largest = i;
    }
  }

  return largest;
}

int main() {
  printf("%d\n", largestPrimeFactor(600851475143));
  return 0;
}
