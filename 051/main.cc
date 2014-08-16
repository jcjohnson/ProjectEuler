#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

void GetDigits(int num, vector<int>* v, int base = 10);
int GetNumber(const vector<int>& digits, int base = 10);
bool IsPrime(int num);

void GetDigits(int num, vector<int>* v, int base) {
  while (num != 0) {
    v->push_back(num % base);
    num /= base;
  }
}

int GetNumber(const vector<int>& digits, int base) {
  int num = 0;
  int p = 1;
  for (int digit : digits) {
    assert(digit < base);
    num += p * digit;
    p *= base;
  }
  return num;
}

bool IsPrime(int num) {
  if (num <= 1) return false;
  if (num == 2) return true;
  if (num % 2 == 0) return false;

  for (int x = 3; x * x <= num; x += 2) {
    if (num % x == 0) return false;
  }
  return true;
}

void FindPrimeFamily(const vector<int>& pattern_digits,
                     vector<int>* prime_family) {
  // If pattern_digits doesn't contain any 10s then return
  bool found_ten = false;
  for (int d : pattern_digits) {
    if (d == 10) {
      found_ten = true;
      break;
    }
  }
  if (!found_ten) {
    return;
  }

  int r_start = 0;
  if (*pattern_digits.rbegin() == 10) r_start = 1;


  for (int r = r_start; r <= 9; r++) {
    vector<int> digits;
    for (int d : pattern_digits) {
      if (d == 10) {
        digits.push_back(r);
      } else {
        digits.push_back(d);
      }
    }
    int num = GetNumber(digits);
    if (IsPrime(num)) {
      prime_family->push_back(num);
    }
  }
}

int main() {
  int pattern = 1;
  while (true) {
    // Interpret pattern in base 11; any 10 digits are *s
    vector<int> pattern_digits;
    GetDigits(pattern, &pattern_digits, 11);

    vector<int> prime_family;
    FindPrimeFamily(pattern_digits, &prime_family);

    if (prime_family.size() == 8) {
      // Print the pattern
      for (auto it = pattern_digits.rbegin(); it != pattern_digits.rend(); ++it) {
        int d = *it;
        if (d == 10) {
          cout << "*";
        } else {
          cout << d;
        }
      }
      cout << endl;
  
      for (int p : prime_family) {
        cout << p << endl;
      }

      break;
    }
    
    pattern++;
  }

  return 0;
}
