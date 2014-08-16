#include <cassert>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename it_t>
void Interleave(const vector<int>& prefix,
                it_t v1_cur,
                it_t v1_end,
                it_t v2_cur,
                it_t v2_end,
                vector<vector<int>>* interleaved) {
  if (v1_cur == v1_end) {
    vector<int> v = prefix;
    v.insert(v.end(), v2_cur, v2_end);
    interleaved->push_back(v);
    return;
  } else if (v2_cur == v2_end) {
    vector<int> v = prefix;
    v.insert(v.end(), v1_cur, v1_end);
    interleaved->push_back(v);
    return;
  }

  if (*v1_cur == *v2_cur) {
    vector<int> v = prefix;
    v.push_back(*v1_cur);
    Interleave(v, v1_cur + 1, v1_end, v2_cur + 1, v2_end, interleaved);
  }

  vector<int> v1 = prefix;
  v1.push_back(*v1_cur);
  Interleave(v1, v1_cur + 1, v1_end, v2_cur, v2_end, interleaved);

  vector<int> v2 = prefix;
  v2.push_back(*v2_cur);
  Interleave(v2, v1_cur, v1_end, v2_cur + 1, v2_end, interleaved);
}

void Interleave(const vector<int>& v1, const vector<int>& v2, vector<vector<int>>* interleaved) {
  Interleave(vector<int>(), v1.begin(), v1.end(), v2.begin(), v2.end(), interleaved);
}

template<typename T>
void PrintVector(const vector<T>& v) {
  for (auto x : v) {
    cout << x << " ";
  }
  cout << endl;
}

void PrintCombinations(const vector<vector<int>>& c) {
  for (auto v : c) {
    for (int x : v) cout << x;
    cout << endl;
  }
}

int main() {
  vector<vector<int>> observations;
  string line;
  while (getline(cin, line)) {
    vector<int> observation;
    for (int i = 0; i < 3; i++) {
      observation.push_back(line[i] - '0');
    }
    observations.push_back(observation);
  }

  PrintCombinations(observations);

  vector<vector<int>> passwords;
  auto it = observations.begin();
  passwords.push_back(*it);
  ++it;

  while (it != observations.end()) {
    vector<vector<int>> interleaved;
    for (const vector<int>& p : passwords) {
      // cout << "Interleaving the following: " << endl;
      // PrintVector(p);
      // PrintVector(*it);
      Interleave(p, *it, &interleaved);
    }

    // Find the smallest size
    int min_length = -1;
    for (const vector<int>& v : interleaved) {
      if (min_length < 0 || v.size() < min_length) {
        min_length = v.size();
      }
    }

    passwords.clear();
    for (const vector<int>& v : interleaved) {
      if (v.size() == min_length) {
        passwords.push_back(v);
      }
    }

    PrintCombinations(passwords);
    cout << "-------------" << endl;

    ++it;
  }
}

