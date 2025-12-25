#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  vector<int> v;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  sort(v.begin(), v.end());
  
  int sum = 0;
  for (int i = 0; i < n - 1; i++) {
    sum += (v[i] + v[i + 1]);
    v[i + 1] = (v[i] + v[i + 1]);
  }

  cout << sum;
  return 0;
}