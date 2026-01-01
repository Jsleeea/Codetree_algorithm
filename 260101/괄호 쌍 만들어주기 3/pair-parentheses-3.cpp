#include <iostream>
using namespace std;

int main(void) {

  string s;
  cin >> s;

  int cnt = 0;

  for (int i = 0; i < s.size(); i++) {
    for (int j = i+1; j < s.size(); j++) {
      if (s[i] == ')') {
        break;
      }

      if (s[j] == ')') {
        cnt++;
      }
    }
  }

  cout << cnt;

  return 0;
}