#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 10;

long getNum(int digits[], int numDigits) {
  long num = 0;
  int pow = 1;
  for (int i = numDigits - 1; i >= 0; i--) {
    num += (long)digits[i] * pow;
    pow *= 10;
  }
  return num;
}

int main() {
  int digits[MAX];
  for (int i = 0; i < MAX; i++) digits[i] = i;

  int primes[] = {2, 3, 5, 7, 11, 13, 17};  

  long sum = 0;
  do {
    if (digits[0] != 0) {
      long num = getNum(digits, MAX);
      bool works = true;
      for (int j = 1; works && j + 2 < MAX; j++) {
        int subNum = getNum(digits + j, 3);
        if (subNum % primes[j - 1] != 0) works = false;
      }
      if (works) {
        cout << num << endl;
        sum += num;
      }
    }
  } while (next_permutation(digits, digits + MAX));

  cout << "sum = " << sum << endl;

  return 0;
}
