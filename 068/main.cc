#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int SIZE = 5;

bool check(const vector<int> &nums) {
  int val = nums[0] + nums[SIZE] + nums[SIZE + 1];
  for (int i = 1; i < SIZE; i++) {
    // Check for solution
    int j = i + SIZE;
    int k = SIZE + ((i + 1) % SIZE);
    if (val != nums[i] + nums[j] + nums[k]) {
      return false;
    }

    // Check for correct order
    if (nums[0] > nums[i]) {
      return false;
    }
  }

  return true;
}

vector<int> getDescription(const vector<int> &nums) {
  vector<int> desc;
  for (int i = 0; i < SIZE; i++) {
    desc.push_back(nums[i]);
    desc.push_back(nums[i + SIZE]);
    desc.push_back(nums[SIZE + ((i + 1) % SIZE)]);
  }
  return desc;
}

void print_vector(const vector<int> &nums) {
  for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
    cout << *it << " ";
  }
  cout << endl;
}

long concatenate(const vector<int> &nums) {
  long ret = 0;
  for (vector<int>::const_iterator it = nums.begin(); it != nums.end(); ++it) {
    int num = *it;
    vector<int> digits;
    while (num != 0) {
      int digit = num % 10;
      num /= 10;
      digits.push_back(digit);
    }
    for (vector<int>::reverse_iterator jt = digits.rbegin(); jt != digits.rend(); ++jt) {
      ret = 10 * ret + *jt;
    }
  }
  return ret;
}

int numDigits(long num) {
  int count = 0;
  while (num != 0) {
    count++;
    num /= 10;
  }
  return count;
}

int main() {
  vector<int> nums;
  for (int i = 1; i <= 2 * SIZE; i++) {
    nums.push_back(i);
  }

  sort(nums.begin(), nums.end());

  long max = 0;

  do {
    if (check(nums)) {
      vector<int> description = getDescription(nums);
      print_vector(description);
      long concat = concatenate(description);
      cout << concat << endl;
      if (concat > max && numDigits(concat) == 16) {
        max = concat;
      }
    }
  } while (next_permutation(nums.begin(), nums.end()));

  cout << endl << max << endl;

  return 0;
}
