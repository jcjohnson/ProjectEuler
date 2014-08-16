#include <stdio.h>

#define N 10001

int main() {
  int primes[N];
  int i = 3;
  int nextIndex = 1;
  int j, isPrime;

  primes[0] = 2;
  while (nextIndex < N) {
    isPrime = 1;
    for (j = 0; j < nextIndex && primes[j] * primes[j] <= i; j++) {
      if (i % primes[j] == 0) {
        isPrime = 0;
        break;
      }
    }
    if (isPrime) primes[nextIndex++] = i;
    i++;
  }

  printf("%d\n", primes[N - 1]);
}
