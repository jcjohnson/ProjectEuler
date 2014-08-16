#ifndef _FRACTION_H_
#define _FRACTION_H_

class Rational {
 public:
  Rational(int n, int d) : n_(n), d_(d) {reduce();}
  Rational(int n) : n_(n), d_(1) { }
  Rational() : n_(0), d_(1) { }
  int num() const {return n_;}
  int den() const {return d_;}
  bool IsInteger() const {return d_ == 1;}
  int ToInteger() const {return n_ / d_;}
  double ToDouble() const {return n_ * 1.0 / d_;}
 private:
  int n_;
  int d_;

  int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
  }

  void reduce() {
    int s = 1;
    s *= (d_ < 0 ? -1 : 1);
    s *= (n_ < 0 ? -1 : 1);

    n_ = (n_ >= 0 ? n_ : -n_);
    d_ = (d_ >= 0 ? d_ : -d_);

    int g = gcd(n_, d_);
    n_ /= g;
    d_ /= g;

    n_ *= s;
  }
};

template<typename S>
S& operator<<(S& os, const Rational& f) {
  os << f.num() << " / " << f.den();
  return os;
}

int Compare(const Rational& f1, const Rational& f2) {
  return f1.num() * f2.den() - f2.num() * f1.den();
}

bool operator==(const Rational& f1, const Rational& f2) {
  return Compare(f1, f2) == 0;
}

bool operator!=(const Rational& f1, const Rational& f2) {
  return !(f1 == f2);
}

bool operator<(const Rational& f1, const Rational& f2) {
  return Compare(f1, f2) < 0;
}

bool operator<=(const Rational& f1, const Rational& f2) {
  return Compare(f1, f2) <= 0;
}

bool operator>(const Rational& f1, const Rational& f2) {
  return Compare(f1, f2) > 0;
}

bool operator>=(const Rational& f1, const Rational& f2) {
  return Compare(f1, f2) >= 0;
}

const Rational operator+(const Rational& f1, const Rational& f2) {
  int n = f1.num() * f2.den() + f2.num() * f1.den();
  int d = f1.den() * f2.den();
  return Rational(n, d);
}

const Rational operator-(const Rational& f) {
  return Rational(-f.num(), f.den());
}

const Rational operator-(const Rational& f1, const Rational& f2) {
  return f1 + (-f2);
}

const Rational operator*(const Rational& f1, const Rational& f2) {
  return Rational(f1.num() * f2.num(), f1.den() * f2.den());
}

const Rational operator/(const Rational& f1, const Rational& f2) {
  return Rational(f1.num() * f2.den(), f1.den() * f2.num());
}

#endif
