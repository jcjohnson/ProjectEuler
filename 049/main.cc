#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

vector<int> getDigits(int num) {
  vector<int> digits;
  while (num != 0) {
    digits.push_back(num % 10);
    num /= 10;
  }
  return digits;
}

int getNum(const vector<int> &digits) {
  int num = 0;
  int pow = 1;
  for (vector<int>::iterator it = digits.begin(); it != digits.end(); ++it) {
    num += pow * (*it);
    pow *= 10;
  }
  return num;
}

set<int> getPerms(int num) {
  vector<int> digits = getDigits(num);
  set<int> perms;

  sort(digits.begin(), digits.end());

  do {
    int num = getNum(digits);
    perms.insert(num);
  } while (next_permutation(digits.begin(), digits.end()));

  return perms;
}

set<int> getPrimes(int low, int high) {
  vector<int> primes;

  for (int p = 2; p < high; p++) {
    bool isPrime = true;
    for (vector<int>::iterator it = primes.begin();
        it != primes.end() && isPrime && (*it) * (*it) <= p; ++it) {
      if (p % *it == 0) isPrime = false;
    }
    if (isPrime) primes.push_back(p);
  }
  
  set<int> ret;
  for (vector<int>::iterator it = primes.begin(); it != primes.end(); ++it) {
    if (low <= *it) ret.insert(*it);
  }

  return ret;
}

int main() {
  set<int> primes = getPrimes(1000, 10000);

  for (set<int>::iterator pit = primes.begin(); pit != primes.end(); pit++) {
    int p = *pit;
    set<int> perms = getPerms(p);
    for (set<int>::iterator xit = perms.begin(); xit != perms.end(); xit++) {
      int x = *xit;
      int y = 2 * x - p;
      if (p < x && perms.count(y) && primes.count(x) && primes.count(y)) {
        cout << p << " " << x << " " << y << endl;
      }
    }
  }

  return 0;
}
