#include <iostream>
#include <vector>

using namespace std;

bool IsPrime(int n) {
  if (n == 1) return false;
  if (n == 2) return true;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return false;
  }
  return true;
}

int GetNextPrime(vector<int>* primes) {
  int p = 0;
  if (primes->empty()) {
    p = 2;
  } else if (primes->size() == 1) {
    p = 3;
  } else {
    for (p = *primes->rbegin() + 2; true; p += 2) {
      bool is_prime = true;
      for (int q : *primes) {
        if (q * q > p) break;
        if (p % q == 0) {
          is_prime = false;
          break;
        }
      }
      if (is_prime) break;
    }
  }
  primes->push_back(p);
  return p;
}

bool SquareProduct(int f1, int f2, vector<int>* primes) {
  // First divide out all primes
  for (int p : *primes) {
    if (f1 == 1 && f2 == 1) {
      return true;
    }
    int count = 0;
    while (f1 % p == 0) {
      f1 /= p;
      count++;
    }
    while (f2 % p == 0) {
      f2 /= p;
      count++;
    }
    if (count % 2 != 0) return false;
  }

  // Now generate primes until we are done
  while (f1 != 1 || f2 != 1) {
    int p = GetNextPrime(primes);
    int count = 0;
    while (f1 % p == 0) {
      f1 /= p;
      count++;
    }
    while (f2 % p == 0) {
      f2 /= p;
      count++;
    }
    if (count % 2 != 0) return false;
  }

  return true;
}

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

bool IsSolution(int x, int D, vector<int>* primes) {
  int f1 = x - 1;
  int f2 = x + 1;
  int g = gcd(f1, D);
  f1 /= g;
  if (f2 % (D / g) != 0) return false;
  f2 /= (D / g);
  return SquareProduct(f1, f2, primes);
}

int SolveForMinX(int D, vector<int>* primes) {
  if (IsPrime(D)) {
    for (int t = 1; true; t++) {
      int x1 = t * D - 1;

      if (t % 1000 == 0) cout << x1 << endl;
      if (IsSolution(x1, D, primes)) {
        return x1;
      }

      int x2 = t * D + 1;
      if (IsSolution(x2, D, primes)) {
        return x2;
      }
    }
  } else {
    for (int x = 2; true; x++) {
      if (IsSolution(x, D, primes)) {
        return x;
      }
    }
  }
}

int main() {
  int last_square = 0;
  int num_squares = 0;

  vector<int> primes;

  SolveForMinX(61, &primes);

  /*
  for (int D = 1; D <= 100; D++) {
    if (D == last_square + 2 * num_squares + 1) {
      last_square = D;
      num_squares++;
      cout << D << " is square" << endl;
      continue;
    }

    int x = SolveForMinX(D);
    cout << "D = " << D << " x = " << x << endl;
  }
  */
}
