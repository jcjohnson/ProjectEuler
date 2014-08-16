#include <vector>
#include <set>
#include <iostream>

using namespace std;

typedef vector<int>::iterator it_t;

// Get a list of all primes p such that p^pow < N
vector<int> genPrimePowers(int N, int pow) {
  vector<int> primes;
  vector<int> nums;
  for (int n = 2; n * n <= N; n++) {
    int prod = 1;
    for (int i = 0; i < pow; i++) prod *= n;
    if (prod > N) break;
    bool prime = true;
    for (it_t it = primes.begin(); it != primes.end(); ++it) {
      int p = *it;
      if (p * p > n) break;
      if (n % p == 0) prime = false;
    }
    if (prime) {
      primes.push_back(n);
      nums.push_back(prod);
    }
  }
  return nums;
}

const int MAX = 50000000;

int main() {
  vector<int> squares = genPrimePowers(MAX, 2);
  vector<int> cubes = genPrimePowers(MAX, 3);
  vector<int> fourths = genPrimePowers(MAX, 4);
  set<int> seen;

  for (unsigned int i2 = 0; i2 < squares.size(); i2++) {
    for (unsigned int i3 = 0; i3 < cubes.size(); i3++) {
      for (unsigned int i4 = 0; i4 < fourths.size(); i4++) {
        int sum = squares[i2] + cubes[i3] + fourths[i4];
        if (sum < MAX) {
          // cout << sum << endl;
          seen.insert(sum);
        }
      }
    }
  }

  cout << seen.size() << endl;

  return 0;
}
