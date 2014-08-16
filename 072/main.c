// This works and is very fast thanks to a smart implementation of phi(n))

#include <stdio.h>

#define MAX 1000001

// fact[n] is 1 if n is prime; otherwise fact[n] is the smallest prime factor of n
int fact[MAX];

int phi(int n) {
  int r, e;
  int p = fact[n];

  if (n <= 1) return 1;
  if (p == 1) return n - 1;

  r = 1;
  e = 0;

  while (n % p == 0) {
    n /= p;
    if (e == 0) {
      r *= (p - 1);
      e = 1;
    } else {
      r *= p;
    }
  }

  return phi(n) * r;
}

int main() {
  int i, j;
  long sum;

  // Initialize fact
  for (i = 0; i < MAX; i++) {
    fact[i] = 1;
  }
  for (i = 2; i < MAX; i++) {
    if (fact[i] == 1) {
      for (j = i + i; j < MAX; j += i) {
        if (fact[j] == 1) {
          fact[j] = i;
        }
      }
    }
  }

  sum = 0;
  for (i = 2; i < MAX; i++) {
    sum += phi(i);
  }

  printf("%ld\n", sum);

  return 0;
}
