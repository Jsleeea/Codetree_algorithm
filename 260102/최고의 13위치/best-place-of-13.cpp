#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n;
  cin >> n;

  int arr[20][20];

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  int cnt = 0;
  for (int i = 0;i<n;i++) {
    for (int j=0;j<n-2;j++) {
      cnt = max(arr[i][j] + arr[i][j+1] + arr[i][j+2], cnt);
    }
  }

  cout << cnt;
  return 0;
}