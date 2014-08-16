#include <iostream>
#include <vector>

using namespace std;

int getNum(vector<int> &digits) {
  int num = 0;
  int pow = 1;
  for (vector<int>::iterator it = digits.begin(); it < digits.end(); ++it) {
    num += pow * *it;
    pow *= 10;
  }
  return num;
}

vector<int> getDigits(int num) {
  vector<int> digits;
  while (num != 0) {
    digits.push_back(num % 10);
    num /= 10;
  }
  return digits;
}

int concatenate(int a, int b) {
  vector<int> digitsA = getDigits(a);
  vector<int> digitsB = getDigits(b);
  for (vector<int>::iterator it = digitsA.begin(); it < digitsA.end(); ++it) {
    digitsB.push_back(*it);
  }
  return getNum(digitsB);
}

bool isPrime(int num) {
  if (num == 2) return true;
  for (int i = 3; i * i <= num; i += 2) {
    if (num % i == 0) return false;
  }
  return true;
}

vector<int> getPrimes(int max) {
  vector<int> primes;
  
  for (int p = 2; p < max; p++) {
    bool isPrime = true;
    for (vector<int>::iterator it = primes.begin();
         it < primes.end() && isPrime && (*it) * (*it) <= p; ++it) {
      if (p % *it == 0) isPrime = false;
    }
    if (isPrime) primes.push_back(p);
  }

  return primes;
}

int main() {
  vector<int> primes = getPrimes(1000000);

  int i[4];
  for (i[0] = 3; true; i[0]++) {
    for (i[1] = 0; i[1] < i[0]; i[1]++) {
      for (i[2] = 0; i[2] < i[1]; i[2]++) {
        for (i[3] = 0; i[3] < i[2]; i[3]++) {
          bool works = true;
          for (int ii = 0; ii < 4 && works; ii++) {
            for (int jj = 0; jj < 4 && works; jj++) if (ii != jj) {
              if (!isPrime(concatenate(primes[i[ii]], primes[i[jj]]))) {
                works = false;
              }
            }
          }
          if (works) {
            int sum = 0;
            for (int ii = 0; ii < 4; ii++) {
              cout << primes[i[ii]] << endl;
              sum += primes[i[ii]];
            }
            cout << "The sum is " << endl;
            return 0;
          }
        }
      }
    }
  }

  return 0;
}
