#include <cmath>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '0') {
      s[i] = '1';
      break;
    }
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