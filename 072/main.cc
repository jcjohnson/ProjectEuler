// This works but is a bit slow.

#include <iostream>
#include <vector>

using namespace std;

void get_primes(vector<int> &primes, int max) {
  for (int n = 2; n <= max; n++) {
    bool prime = true;
    for (unsigned int i = 0; prime && i < primes.size() && primes[i] * primes[i] <= n; i++) {
      if (n % primes[i] == 0) prime = false;
    }
    if (prime) {
      primes.push_back(n);
    }
  }
}

int phi(int n, const vector<int> &primes) {
  // phi(p^k) = p^(k-1) * (p - 1)
  int ret = 1;
  for (vector<int>::const_iterator it = primes.begin(); it != primes.end(); ++it) {
    int p = *it;
    long pp = p * p;
    if (p != n && pp > n) continue;
    if (p > n) break;
    // if (p > n) break;
    bool found = false;
    while (n % p == 0) {
      if (!found) {
        found = true;
        ret *= (p - 1);
      } else {
        ret *= p;
      }
      n /= p;
    }
  }
  return ret;
}

const int MAX = 1000000;

int main() {
  vector<int> primes;
  get_primes(primes, MAX);

  cout << "got primes" << endl;

  long count = 0;
  for (int d = 2; d <= MAX; d++) {
    if (d % 1000 == 0) 
      cout << "d = " << d << "\tcount = " << count << endl;
    // int phid = phi(d, primes);
    // cout << d << "\t" << phid << endl;
    count += phi(d, primes);
  }

  cout << count << endl;
  
  return 0;
}
