#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> getPrimes(int max) {
  vector<int> primes;
  for (int i = 2; i < max; i++) {
    bool isPrime = true;
    for (int j = 0; isPrime && j < primes.size() && primes[j] * primes[j] <= i; j++) {
      if (i % primes[j] == 0) isPrime = false;
    }
    if (isPrime) primes.push_back(i);
  }
  return primes;
}

const int MAX = 1000000;

int main() {
  vector<int> primeVec = getPrimes(MAX);
  set<int> primeSet;
  for (int i = 0; i < primeVec.size(); i++) primeSet.insert(primeVec[i]);

  // Vector of partial sums to allow for sums of consecutive primes to be
  // computed in constant time.
  vector<int> primeSum(primeVec);
  for (int i = 1; i < primeSum.size(); i++) primeSum[i] += primeSum[i - 1];

  for (int length = 2; length < primeVec.size(); length++) {
    for (int start = 0; start + length - 1 < primeVec.size(); start++) {
      int sum = primeSum[start + length - 1];
      if (start > 0) sum -= primeSum[start - 1];
      if (primeSet.count(sum) > 0) {
        cout << sum << " is the sum of " << length << " consecutive primes." << endl;
        break;
      }
    }
  }

  return 0;
}
