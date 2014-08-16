#include <algorithm>
#include <set>
#include <iostream>
#include <utility>
#include <vector>

#include "../util/Rational.h"

using namespace std;

void PerformBinaryOperations(const Rational& a, const Rational& b, set<Rational>* s) {
  s->insert(a + b);
  s->insert(a * b);
  s->insert(a - b);
  s->insert(b - a);
  if (b != 0) s->insert(a / b);
  if (a != 0) s->insert(b / a);
}

void PerformAllBinaryOperations(int a, int b, int c, int d, set<int>* results) {
  vector<int> elems = {a, b, c, d};
  set<Rational> all_results;
  do {
    a = elems[0];
    b = elems[1];
    c = elems[2];
    d = elems[3];

    // Case I: ((a b) c) d
    {
      set<Rational> s1;
      PerformBinaryOperations(a, b, &s1);
      set<Rational> s2;
      for (const Rational& x : s1) PerformBinaryOperations(x, c, &s2);
      for (const Rational& x : s2) PerformBinaryOperations(x, d, &all_results);
    }

    // Case II: (a b) (c d)
    {
      set<Rational> s1;
      set<Rational> s2;
      PerformBinaryOperations(a, b, &s1);
      PerformBinaryOperations(c, d, &s2);
      for (const Rational& x : s1) for (const Rational& y : s2) PerformBinaryOperations(x, y, &all_results);
    }

    // Case III: (a (b c)) d
    {
      set<Rational> s1;
      PerformBinaryOperations(b, c, &s1);
      set<Rational> s2;
      for (const Rational& x : s1) PerformBinaryOperations(a, x, &s2);
      for (const Rational& x : s2) PerformBinaryOperations(x, d, &all_results);
    }

    // Case IV: a ((b c) d)
    {
      set<Rational> s1;
      PerformBinaryOperations(b, c, &s1);
      set<Rational> s2;
      for (const Rational& x : s1) PerformBinaryOperations(x, d, &s2);
      for (const Rational& x : s2) PerformBinaryOperations(a, x, &all_results);
    }

    // Case V: a (b (c d))
    {
      set<Rational> s1;
      PerformBinaryOperations(c, d, &s1);
      set <Rational> s2;
      for (auto x : s1) PerformBinaryOperations(b, x, &s2);
      for (auto x : s2) PerformBinaryOperations(a, x, &all_results);
    }
  } while (next_permutation(elems.begin(), elems.end()));

  for (const Rational& x : all_results) {
    // cout << x << " = " << x.ToDouble() << endl;
    if (x > 0 && x.IsInteger()) {
      results->insert(x.ToInteger());
    }
  }
}

int LongestStreakLength(const set<int>& s) {
  int i = 1;
  for (int x : s) {
    if (x != i) return i - 1;
    i++;
  }
  return i - 1;
}

int main() {
    
  int max_length = 0;
  for (int a = 1; a < 10; a++) {
    for (int b = a + 1; b < 10; b++) {
      for (int c = b + 1; c < 10; c++) {
        for (int d = c + 1; d < 10; d++) {
          set<int> results;
          PerformAllBinaryOperations(a, b, c, d, &results);
          int length = LongestStreakLength(results);
          // cout << length << " " << a << b << c << d << endl;
          if (length > max_length) {
            max_length = length;
            cout << length << " " << a << b << c << d << endl;
          }
        }
      }
    }
  }
 
  return 0;
}
