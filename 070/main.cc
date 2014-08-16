#include <iostream>
#include <vector>
#include <set>

using namespace std;

void GetDigitHist(int n, vector<int>* hist) {
  int base = 10;
  hist->clear();
  for (int i = 0; i <= base; i++) {
    hist->push_back(0);
  }

  while (n != 0) {
    int d = n % base;
    n /= base;
    (*hist)[d]++;
  }
}

bool ArePermutations(int a, int b) {
  vector<int> hist_a;
  GetDigitHist(a, &hist_a);

  vector<int> hist_b;
  GetDigitHist(b, &hist_b);

  return hist_a == hist_b;
}

void SievePrimes(int N, set<int>* primes) {
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

  primes->clear();
  for (int i = 2; i <= N; i++) {
    if (is_prime[i]) primes->insert(i);
  }
}

void ComputeAllPhi(int N, const set<int>& primes, vector<int>* phi) {
  vector<int>& memo = *phi;
  memo.clear();
  memo.reserve(N + 1);

  memo[1] = 1;
  for (int n = 2; n <= N; n++) {
    bool noisy = false;
    if (n % (N / 100) == 0) noisy = true;
    if (noisy) cout << (n / (N / 100)) << "%" << endl;

    if (primes.find(n) != primes.end()) {
      // n is prime
      memo[n] = n - 1;
    } else {  
      int num_checked = 0;
      for (int p : primes) {
        num_checked++;
        if (n % p == 0) {
          int pk = 1;
          int phi_pk = 1;
          int nn = n;
          bool first = true;
          while (nn % p == 0) {
            nn /= p;
            pk *= p;
            phi_pk *= (first ? (p - 1) : p);
            first = false;
          }
          memo[n] = phi_pk * memo[nn];
          break;
        }
      }
      if (num_checked > 10000) {
        cout << n << " " << num_checked << endl;
      }
    }
  }
}

int main() {
  int N = 10000000;
  set<int> primes;

  SievePrimes(N, &primes);
  
  vector<int> phi;
  ComputeAllPhi(N, primes, &phi);

  double min_ratio;
  int min_n;
  bool min_ratio_initialized = false;
  for (int n = 2; n <= N; n++) {
    int pn = phi[n];
    if (ArePermutations(n, pn)) {
      double ratio = ((double)n / pn);
      if (!min_ratio_initialized || ratio < min_ratio) {
        min_ratio_initialized = true;
        min_ratio = ratio;
        min_n = n;
      }
    }
  }
  cout << min_n << endl;

  return 0;
}
