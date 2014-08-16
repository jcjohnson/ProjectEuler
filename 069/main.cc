#include <iostream>
#include <vector>

using namespace std;

void computePrimes(vector<int> &p, int max) {
  for (int n = 2; n <= max; n++) {
    bool prime = true;
    for (unsigned int i = 0; prime && i < p.size() && p[i] * p[i] <= n; i++) {
      if (n % p[i] == 0) prime = false;
    }
    if (prime) p.push_back(n);
  }
}

int phi(int n, const vector<int> &primes) {
  int ret = 1;
  for (vector<int>::const_iterator it = primes.begin(); it != primes.end(); ++it) {
    int p = *it;
    bool divisible = false;
    if (p > n) {
      break;
    }
    while (n % p == 0) {
      if (divisible) ret *= p;
      divisible = true;
      n /= p;
    }
    if (divisible) {
      ret *= (p - 1);
    }
  }
  return ret;
}

bool fracLess(int n1, int d1, int n2, int d2) {
  return n1 * d2 < n2 * d1;
}

const int MAX = 1000000;

int main() {
  vector<int> primes;
  computePrimes(primes, MAX);
  int maxN = 0;
  int maxD = 1;
  for (int n = 1; n <= MAX; n++) {
    int d = phi(n, primes);
    if (fracLess(maxN, maxD, n, d)) {
      maxN = n;
      maxD = d;
    }
  }
  cout << maxN << endl;
  return 0;
}
