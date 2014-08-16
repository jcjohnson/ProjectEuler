#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> decrypt(vector<char> &data, const vector<char> &key) {
  int index = 0;
  vector<char> decrypted;
  for (vector<char>::iterator it = data.begin(); it < data.end(); ++it) {
    decrypted.push_back(*it ^ key[index]);
    index = (index + 1) % 3;
  }
  return decrypted;
}

void print(vector<char> &data) {
  for (vector<char>::iterator it = data.begin(); it < data.end(); ++it) {
    cout << *it;
  }
  cout << endl;
}

int main() {
  vector<char> encrypted;

  int val;
  while (cin >> val) {
    encrypted.push_back(val);
  }

  int maxSpaces = 0;
  vector<char> bestKey;
  vector<char> key(3);
  for (key[0] = 'a'; key[0] <= 'z'; key[0]++) {
    for (key[1] = 'a'; key[1] <= 'z'; key[1]++) {
      for (key[2] = 'a'; key[2] <= 'z'; key[2]++) {
        vector<char> decrypted = decrypt (encrypted, key);

        int numSpaces = count(decrypted.begin(), decrypted.end(), ' ');
        if (numSpaces > maxSpaces) {
          maxSpaces = numSpaces;
          bestKey = key;
        }
      }
    }
  }

  vector<char> decrypted = decrypt(encrypted, bestKey);
  cout << "Here is the decrypted text:" << endl;
  print(decrypted);

  int sum = 0;
  for (vector<char>::iterator it = decrypted.begin(); it < decrypted.end(); ++it) {
    sum += *it;
  }
  cout << endl << "Sum is " << sum << endl;
  

  return 0;
}
