#include <iostream>
#include <set>

using namespace std;

int fact[10];

void initFact() {
  fact[0] = 1;
  for (int n = 1; n < 10; n++) {
    fact[n] = n * fact[n - 1];
  }
}

int nextNum(int n) {
  int sum = 0;
  while (n != 0) {
    int d = n % 10;
    sum += fact[d];
    n /= 10;
  }
  return sum;
}

int chainLength(int num) {
  set<int> seen;

  do {
    seen.insert(num);
    num = nextNum(num);
  } while (seen.find(num) == seen.end());

  return seen.size();
}

int main() {
  initFact();

  int count = 0;
  for (int start = 1; start <= 1000000; start++) {
    if (chainLength(start) == 60) count++;
  }

  cout << count << endl;

  return 0;
}
