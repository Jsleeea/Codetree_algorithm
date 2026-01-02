#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int arr[100];

  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  int ans = 0;

  for (int i = 0; i < n - k + 1; i++) {
    int sum = 0;
    for (int j = i; j < i + k; j++) {
      sum += arr[j];
    }
    ans = max(ans, sum);
  }

  cout << ans;
  return 0;
}