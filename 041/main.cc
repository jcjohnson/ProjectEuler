#include <vector>
#include <iostream>

using namespace std;

vector<int> getDigits(int num) {
  vector<int> digits;
  while (num != 0) {
    digits.push_back(num % 10);
    num /= 10;
  }
  return digits;
}

bool isPandigital(int num) {
  vector<int> digits = getDigits(num);

  bool seen[digits.size() + 1];
  seen[0] = true;
  for (int i = 1; i <= digits.size(); i++) seen[i] = false;

  for (int i = 0; i < digits.size(); i++) {
    if (digits[i] > digits.size() || seen[digits[i]]) {
      return false;
    }
    seen[digits[i]] = true;
  }

  for (int i = 0; i <= digits.size(); i++) {
    if (!seen[i]) {
      return false;
    }
  }
  
  return true;
}

// const int MAX = 987654321;
const int MAX = 100000000;

int main() {
  vector<int> primes;
  primes.push_back(2);

  for (int i = 3; i <= MAX; i += 2) {
    bool isPrime = true;

    for (int j = 0; isPrime && j < primes.size() && primes[j] * primes[j] <= i; j++) {
      if (i % primes[j] == 0) {
        isPrime = false;
      }
    }

    if (isPrime) {
      primes.push_back(i);
      if (isPandigital(i)) {
        cout << i << " is pandigital" << endl;
      }
    }
  }
}
