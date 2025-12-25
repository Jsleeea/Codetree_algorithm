#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool compare(string a, string b) {
  if (a + b > b + a) {
    return true;
  }
  return false;
}

int main(void) {

  int n;
  cin >> n;

  vector<string> v(n);

  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  sort(v.begin(), v.end(), compare);

  for (int i = 0; i < n; i++) {
    cout << v[i];
  }
  return 0;
}