#include <iostream>
#include <vector>

using namespace std;

class DecimalNumber {
 public:
  DecimalNumber(int n) : base_(10), digits_(), exponent_(0) {
    while (n != 0) {
      digits_.push_back(n % base_);
      n /= base_;
    }
  }

  void DivideByBase() {
    exponent_--;
  }
 
 private:
  int base_;
  vector<int> digits_;
  int exponent_;

 friend const DecimalNumber operator*(const DecimalNumber& left,
                                      const DecimalNumber& right);

 friend const DecimalNumber mean(const DecimalNumber& left,
                                 const DecimalNumber& right);

 template<typename S>
 friend S& operator<<(S& os, const DecimalNumber& num);
};

const DecimalNumber operator*(const DecimalNumber& left,
                              const DecimalNumber& right) {
  return left;
}

const DecimalNumber mean(const DecimalNumber& left,
                         const DecimalNumber& right) {
  
}

template<typename S>
S& operator<<(S& os, const DecimalNumber& num) {
  for (auto it = num.digits_.rbegin(); it != num.digits_.rend(); ++it) {
    os << *it;
  }
  os << " * " << num.base_ << "^" << num.exponent_;

  return os;
}

int main() {
  int num_squares = 0;
  int next_square = 1;
  for (int n = 1; n <= 100; n++) {
    if (n == next_square) {
      cout << n << " is square" << endl;
      num_squares++;
      next_square += 2 * num_squares + 1;
    } else {
      vector<int> digits;
      int s = SquareRoot(n, 10, &digits);
      cout << n << " " << s << endl;
    }
  }

  return 0;
}
