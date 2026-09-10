#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, m;

  cin >> n >> m;

  string left;
  string right;

  cin >> left;

  for (int i = 0; i < m; i++) {
    char cmd;
    cin >> cmd;

    if (cmd == 'L') {
      if (!left.empty()) {
        right.push_back(left.back());
        left.pop_back();
      }
    }else if (cmd == 'R') {
      if (!right.empty()) {
        left.push_back(right.back());
        right.pop_back();
      }
    }else if (cmd == 'D') {
      if (!right.empty()) {
        right.pop_back();
      }
    }else if (cmd == 'P') {
      char c;
      cin >> c;

      left.push_back(c);
    }

  }

  reverse(right.begin(), right.end());

  cout << left << right;
  return 0;
}