#include <cmath>
#include <iostream>

using namespace std;

bool IsSquare(long long int n, long long int* s) {
  int ss = 0;
  *s = 0;
  while (true) {
    if (ss == n) return true;
    if (ss > n) return false;
    ss += 2 * (*s) + 1;
    (*s)++;
  }
}

const long long int MAX = 1000000000;

int solve_slow() {
  int sum = 0;
  for (long long int x = 2; 3 * x - 1 <= MAX; x++) {
    int p1 = 3 * x + 1;
    if (p1 <= MAX) {
      long long int s;
      if (IsSquare(3 * x * x - 2 * x - 1, &s)) {
        if (((x + 1) * s) % 4 == 0) {
          cout << x << " " << x << " " << (x + 1) << endl;
          sum += p1;
        }
      }
    }
    int p2 = 3 * x - 1;
    if (p2 <= MAX && x > 1) {
      long long int s;
      if (IsSquare(3 * x * x + 2 * x - 1, &s)) {
        if (((x - 1) * s) % 4 == 0) {
          cout << x << " " << x << " " << (x - 1) << endl;
          sum += p2;
        }
      }
    }
  }
  return sum;
}

double heron(int a, int b, int c) {
  double s = (a + b + c) / 2.0;
  return sqrt(s * (s - a) * (s - b) * (s - c));
}

long long int solve_bigger() {
  long long int sum = 0;

  long long int x = 2;
  long long int xx = 7;
  long long int y = 1;
  long long int yy = 1;
  long long int p = 7;
  while (p <= MAX) {
    if (xx == yy) {
      if ((y * (x + 1)) % 4 == 0) {
        sum += p;

        cout << x << " " << x << " " << (x + 1) << endl;
        // cout << p << endl;
        // cout << xx << " " << yy << endl;
        // cout << sum << endl;
        // cout << endl;
      }

      // Update x
      xx += (6 * x + 1);
      x++;
      p += 3;

      // Update y
      yy += (2 * y + 1);
      y++;
    } else if (xx < yy) {
      xx += (6 * x + 1);
      x++;
      p += 3;
    } else if (yy < xx) {
      yy += (2 * y + 1);
      y++;
    }
  }

  return sum;
}

long long int solve_smaller() {
  long long int sum = 0;

  long long int x = 2;
  long long int xx = 15;
  long long int y = 1;
  long long int yy = 1;
  long long int p = 5;
  while (p <= MAX) {
    if (xx == yy) {
      if ( (y * (x - 1)) % 4 == 0) {
        sum += p;
        
        cout << x << " " << x << " " << (x - 1) << endl;
        // cout << p << endl;
        // cout << xx << endl;
        // cout << sum << endl;
        // cout << endl;
      }
      xx += (6 * x + 5);
      x++;
      p += 3;

      yy += (2 * y + 1);
      y++;
    } else if (xx < yy) {
      xx += (6 * x + 5);
      x++;
      p += 3;
    } else if (yy < xx) {
      yy += (2 * y + 1);
      y++;
    }
  }
  return sum;
}

int main() {
  long long int sum = solve_bigger() + solve_smaller();
  cout << sum << endl;
  return 0;
}
