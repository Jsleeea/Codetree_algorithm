#include <algorithm>
#include <iostream>
using namespace std;

#define INF 1e9

int arr[100][2];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1];
  }

  int ans = INF;

  int min_x{10000000}, max_x{0}, min_y{1000000}, max_y{0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) {
        continue;
      }
      min_x = min(min_x, arr[j][0]);
      max_x = max(max_x, arr[j][0]);
      min_y = min(min_y, arr[j][1]);
      max_y = max(max_y, arr[j][1]);
    }
    ans = min(ans, (max_x - min_x) * (max_y - min_y));
    min_x = 10000000;
    max_x = 0;
    min_y = 10000000;
    max_y = 0;
  }

  cout << ans;
  return 0;
}