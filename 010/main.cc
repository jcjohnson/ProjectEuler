#include <iostream>
#include <vector>

using namespace std;

void find_primes(int max, vector<int>* primes) {
  primes->clear();
  if (max < 2) return;
  primes->push_back(2);
  for (int x = 3; x < max; x++) {
    bool is_prime = true;
    for (int p : *primes) {
      if (p * p > x) break;
      if (x % p == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime) primes->push_back(x);
  }
}

int main() {
  vector<int> primes;
  int max = 2000000;
  find_primes(max, &primes);
  long long int sum = 0;
  for (int p : primes) {
    sum += p;
  }
  cout << sum << endl;
  return 0;
}
