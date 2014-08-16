#include <iostream>
#include <cmath>
#include <string>

using namespace std;

bool isTriangle(int x) {
  for (int i = 1; x > 0; i++) x -= i;
  return x == 0;
}

int getSum(const string &s) {
  int sum = 0;
  for (int i = 0; i < s.size(); i++) {
    sum += s[i] - 'A' + 1;
  }
  return sum;
}

int main() {
  string s;
  int count = 0;
  while (getline(cin, s)) {
    if (isTriangleFast(getSum(s))) count++;
  }
  cout << count << endl;
}
