#include <iostream>
#include <vector>

using namespace std;

vector<int> getPrimes(int num) {
  vector<int> primes;
  for (int i = 2; primes.size() < num; i++) {
    bool isPrime = true;
    for (int j = 0; isPrime && j < primes.size() && primes[j] * primes[j] <= i; j++) {
      if (i % primes[j] == 0) isPrime = false;
    }
    if (isPrime) primes.push_back(i);
  }
  return primes;
}

int numFactors(int n, const vector<int> &primes) {
  int factors = 0;
  for (int i = 0; i < primes.size() && primes[i] <= n; i++) {
    if (n % primes[i] == 0) factors++;
  }
  return factors;
}

int main() {
  const int numPrimes = 20000;
  vector<int> primes = getPrimes(numPrimes);

  int count = 0;
  for (int i = 1; i < primes[numPrimes - 1]; i++) {
    if (numFactors(i, primes) >= 4) {
      count++;
    } else {
      count = 0;
    }
    if (count == 4) {
      cout << i - 3 << endl;
      return 0;
    }
  }

  return 0;
}
