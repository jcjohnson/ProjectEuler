#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<int> getDigits(int num) {
  vector<int> digits;
  while (num != 0) {
    digits.push_back(num % 10);
    num /= 10;
  }
  return digits;
}

bool isPandigital(const vector<int> &digits) {
  if (!digits.size() == 9) return false;

  bool seen[10];
  for (int i = 1; i <= 9; i++) seen[i] = false;
  seen[0] = true;

  for (int i = 0; i < (int) digits.size(); i++) {
    if (seen[digits[i]]) return false;
    seen[digits[i]] = true;
  }

  for (int i = 1; i <= 9; i++) {
    if (!seen[i]) return false;
  }
  
  return true;
}

void addAll(vector<int> &v, const vector<int> &w) {
  for (int i = 0; i < (int) w.size(); i++) v.push_back(w[i]);
}

vector<int> getProduct(int a, int b) {
  vector<int> digits;
  addAll(digits, getDigits(a));
  addAll(digits, getDigits(b));
  addAll(digits, getDigits(a * b));
  return digits;
}

int main() {
  int sum = 0;
  set<int> seen;

  const int MAX = 1000000;
  for (int a = 1; a <= MAX; a++) {
    for (int b = 1; b <= a; b++) {
      int c = a * b;
      vector<int> digits = getProduct(a, b);
      if (digits.size() > 9) break;
      if (isPandigital(digits) && !seen.count(c)) {
        sum += c;
        seen.insert(c);
        cout << a << " x " << b << " = " << c << endl;
      }
    }
  }

  cout << "sum = " << sum << endl;

  return 0;
}
