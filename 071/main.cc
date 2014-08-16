#include <iostream>
#include <vector>
#include <set>

using namespace std;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

class Fraction {
 public:
  Fraction(int num, int den) : num_(num), den_(den) { }

  int num() const {return num_;}
  int den() const {return den_;}

  bool operator<(const Fraction& other) const {
    return num_ * other.den_ < other.num_ * den_;
  }

  bool operator<=(const Fraction& other) const {
    return num_ * other.den_ <= other.num_ * den_;
  }

 private:
  int num_;
  int den_;
};

// Way to lazy to look up the right type for the stream so just make it a
// template.
template<typename S>
S& operator<<(S& os, const Fraction& f) {
  os << f.num() << " / " << f.den();
  return os;
}

// Use binary search to find the largest n such that n / d < target
int BinarySearch(int d, const Fraction& target) {
  int low = 0;  // Invariant: low / d < target
  int high = d;  // Invariant: high / d >= target
  while (low + 1 != high) {
    int mid = (low + high) / 2;
    Fraction f(mid, d);
    if (f < target) {
      low = mid;
    } else {
      high = mid;
    }
  }
  return low;
}

const int MAX_D = 1000000;

int main() {
  Fraction target(3, 7);
  Fraction best(0, 1);
  for (int d = 2; d <= MAX_D; d++) {
    int n = BinarySearch(d, target);

    // n / d is the largest fraction less than target, but it might not be in
    // lowest terms.
    while (gcd(n, d) != 1 && n > 0) n--;

    // Now n / d is the largest fraction in lowest terms with denominator d
    // such that n / d < target.

    Fraction f(n, d);
    if (best < f) {
      best = f;
    }
  }

  cout << best << endl;

  return 0;
}
