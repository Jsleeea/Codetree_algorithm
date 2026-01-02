#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  int cnt = 0;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      s[i] = '1';
      cnt = 1;
      break;
    }
  }

  if (cnt) {
    s[s.size()-1] = '0';
  }

  int sum = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      sum += pow(2, s.size() - 1 - i);
    }
  }

  cout << sum;
  return 0;
}