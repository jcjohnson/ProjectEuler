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

int main() {
  vector<int> primes = getPrimes(100);
  for (int i = 0; i < primes.size(); i++) {
    cout << primes[i] << endl;
  }
}
