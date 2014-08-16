#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

void GeneratePrimes(int N, set<int>* primes) {
  vector<bool> is_prime(N + 1, true);
  is_prime[0] = false;
  is_prime[1] = false;
  for (int i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }
  for (int i = 0; i <= N; i++) {
    if (is_prime[i]) {
      primes->insert(i);
    }
  }
}

void CountPrimeSumsHelper(int cur, int N,
                          set<int>::iterator start,
                          set<int>::iterator end,
                          map<int, int>* counts) {
  if (counts->find(cur) == counts->end()) {
    (*counts)[cur] = 0;
  }
  (*counts)[cur]++;

  for (auto it = start; it != end; ++it) {
    int next = cur + *it;
    if (next <= N) {
      CountPrimeSumsHelper(next, N, it, end, counts);
    }
  }
}

void CountPrimeSums(int N, const set<int>& primes, map<int, int>* counts) {
  CountPrimeSumsHelper(0, N, primes.begin(), primes.end(), counts);
}

int main() {
  for (int N = 10; true; N *= 2) {
    cout << "N = " << N << endl;
    set<int> primes;
    GeneratePrimes(N, &primes);
   
    map<int, int> counts;
    CountPrimeSums(N, primes, &counts);

    for (auto it = counts.begin(); it != counts.end(); ++it) {
      int n = it->first;
      int count = it->second;
      if (count > 5000) {
        cout << n << " " << count << endl;
        return 0;
      }
    }
  }
}
