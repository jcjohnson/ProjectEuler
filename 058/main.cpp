#include <vector>
#include <iostream>

using namespace std;

bool isPrime(int num) {
  if (num == 2) return true;
  for (int i = 3; i * i <= num; i += 2) {
    if (num % i == 0) return false;
  }
  return true;
}

int main() {
  int numerator = 0;
  int denominator = 1;
  int last = 1;
  for (int sideLength = 3; true; sideLength += 2) {
    denominator += 4;
    for (int i = 0; i < 4; i++) {
      last += sideLength - 1;
      if (isPrime(last)) numerator++;
    }
    if (10 * numerator < denominator) {
      cout << sideLength << endl;
      return 0;
    }
  }
}
