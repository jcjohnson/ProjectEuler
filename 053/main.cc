#include <iostream>
#include <set>

using namespace std;

const int N = 100;
const int T = 1000000;

int main() {
  set<long> nums;

  long ncr[N + 1][N + 1];
  for (int n = 0; n <= N; n++) ncr[n][0] = 1;
  for (int k = 1; k <= N; k++) ncr[0][k] = 0;

  for (int n = 1; n <= N; n++) {
    for (int k = 1; k <= N; k++) {
      ncr[n][k] = ncr[n-1][k-1] + ncr[n-1][k];
      if (ncr[n][k] > T) nums.insert(ncr[n][k]);
      if (ncr[n][k] < 0) cout << "OVERFLOW at nCr(" << n << ", " << k << ")" << endl;
    }
  }

  cout << nums.size() << endl;
}
