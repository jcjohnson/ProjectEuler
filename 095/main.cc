#include <algorithm>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

void GetPrimes(int N, vector<int>* primes) {
  vector<bool> is_prime(N + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;

  for (int i = 1; i * i <= N; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }

  for (int i = 1; i <= N; i++) {
    if (is_prime[i]) primes->push_back(i);
  }
}

void GetDivisorSums(int N, const vector<int>& primes,
                    vector<int>* divisor_sums_ptr) {
  vector<int>& divisor_sums = *divisor_sums_ptr;

  set<int> primes_set(primes.begin(), primes.end());

  divisor_sums = vector<int>(N + 1, 0);
  divisor_sums[1] = 1;
  for (int n = 2; n <= N; n++) {
    if (primes_set.find(n) != primes_set.end()) {
      divisor_sums[n] = n + 1;
      continue;
    }

    for (int p : primes) {
      int k = 0;
      int pk = 1;
      int s = 1;
      int m = n;
      while (m % p == 0) {
        k++;
        pk *= p;
        s += pk;
        m /= p;
      }
      if (k > 0) {
        if (m == 1) {
          divisor_sums[n] = s;
        } else {
          divisor_sums[n] = divisor_sums[pk] * divisor_sums[m];
        }
        break;
      }
    }
  }
}

int main() {
  int N = 1000000;
  vector<int> primes;
  GetPrimes(N, &primes);

  vector<int> divisor_sums;
  GetDivisorSums(N, primes, &divisor_sums);

  // Make divisors_sums into sums of proper divisors
  for (int n = 0; n <= N; n++) {
    divisor_sums[n] -= n;
    // cout << n << " " << divisor_sums[n] << endl;
  }

  vector<int> longest_chain;

  // Look for amicable chains
  vector<bool> seen(N + 1, false);
  for (int n = 1; n <= N; n++) {
    if (!seen[n]) {
      int cur = n;
      vector<int> chain;
      bool done = false;
      while (!done) {
        seen[cur] = true;
        chain.push_back(cur);

        int next = divisor_sums[cur];
        if (next <= N && seen[next]) {
          done = true;
          auto it = find(chain.begin(), chain.end(), next);
          if (chain.end() - it > longest_chain.size()) {
            longest_chain.clear();
            longest_chain.insert(longest_chain.begin(), it, chain.end());
          }
        } else if (next > N) {
          done = true;
        }

        cur = next;
      }
    }
  }

  // Find the smallest element of the longest chain
  int smallest = -1;
  for (int c : longest_chain) {
    if (smallest < 0 || c < smallest) {
      smallest = c;
    }
  }
  cout << smallest << endl;

  return 0;
}
