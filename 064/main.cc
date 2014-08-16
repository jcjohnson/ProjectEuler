#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

const double EPSILON = 0.1;

int gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int square(int x) {
  return x * x;
}

int ComputeSequence(int n, bool noisy = false);

int ComputeSequence(int n, bool noisy) {
  if (noisy) cout << "n = " << n << endl;

  vector<int> xs, ys, zs, ws;
  int x = 1, y = 1, z = 0, w = 1;
  for (int i = 0; true; i++) {
    int a = (int)floor(x * sqrt(n) / y + ((double)z) / w);
    if (noisy) cout << a << " ";
    
    int xx = x * y * w * w;
    int yy = x * x * w * w * n - square(y * w * a - y * z);
    int zz = y * w * (y * w * a - y * z);
    int ww = yy;

    x = xx / gcd(xx, yy);
    y = yy / gcd(xx, yy);
    z = zz / gcd(zz, ww);
    w = ww / gcd(zz, ww);

    for (int j = 0; j < xs.size(); j++) {
      if (xs[j] == x && ys[j] == y && zs[j] == z && ws[j] == w) {
        if (noisy) cout << endl << endl;
        return (i - j);
      }
    }

    xs.push_back(x);
    ys.push_back(y);
    zs.push_back(z);
    ws.push_back(w);
  }
}

int main() {
  int last_square = 0;
  int num_squares = 0;
  int num_odd_period = 0;
  for (int n = 1; n <= 10000; n++) {
    if (n == last_square + 2 * num_squares + 1) {
      last_square = n;
      num_squares++;
      // cout << n << " is a square" << endl;
    } else {
      int period = ComputeSequence(n);
      if (period % 2 == 1) num_odd_period++;
      // cout << n << " has period " << period << endl;
    }
  }
  cout << num_odd_period << endl;

  return 0;
}
