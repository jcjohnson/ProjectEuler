#include <cassert>
#include <iostream>
#include <vector>
#include <set>

using namespace std;

template<typename T>
inline bool Contains(const set<T>& s, const T& x) {
  return s.find(x) != s.end();
}

void ExpandDigitSets(const set<set<int>>& seeds, set<set<int>>* digit_sets) {
  for (const set<int>& s : seeds) {
    for (int i = 0; i <= 9; i++) {
      set<int> ss(s);
      if (ss.find(i) == ss.end()) {
        ss.insert(i);
        digit_sets->insert(ss);
      }
    }
  }
}

void GetAllDigitSets(int size, set<set<int>>* digit_sets) {
  *digit_sets = {set<int>()};

  for (int i = 0; i < size; i++) {
    set<set<int>> seeds = *digit_sets;
    digit_sets->clear();
    ExpandDigitSets(seeds, digit_sets);
  }
}

void GetDiceArrangements(const set<set<int>>& digit_sets,
                         vector<set<int>>* dice_arrangements) {
  for (const set<int>& digit_set : digit_sets) {
    set<int> s;
    for (int i = 0; i <= 9; i++) {
      if (digit_set.find(i) == digit_set.end()) {
        s.insert(i);
      }
    }
    if (Contains(s, 6) || Contains(s, 9)) {
      s.insert(6);
      s.insert(9);
    }
    dice_arrangements->push_back(s);
  }
}

bool CanMakeAllTargets(const set<int>& targets,
                       const set<int>& digits1,
                       const set<int>& digits2) {
  for (int target : targets) {
    assert(target < 100);
    int tens = target / 10;
    int ones = target % 10;
    bool can_make = (Contains(digits1, ones) && Contains(digits2, tens)) ||
                    (Contains(digits1, tens) && Contains(digits2, ones));
    if (!can_make) return false;
  }

  return true;
}

int main() {
  set<set<int>> digit_sets;
  GetAllDigitSets(4, &digit_sets);

  vector<set<int>> dice_arrangements;
  GetDiceArrangements(digit_sets, &dice_arrangements);

  cout << dice_arrangements.size() << endl;

  set<int> targets = {1, 4, 9, 16, 25, 36, 49, 64, 81};
  int count = 0;

  for (auto it1 = dice_arrangements.begin(); it1 != dice_arrangements.end(); ++it1) {
    for (auto it2 = it1; it2 != dice_arrangements.end(); ++it2) {
      if (CanMakeAllTargets(targets, *it1, *it2)) count++;
    }
  }
  
  cout << count << endl;

  return 0;
}
