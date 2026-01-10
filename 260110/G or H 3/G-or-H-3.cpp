#include <algorithm>
#include <iostream>
using namespace std;

int arr[10001];
int ans =0;

int main() {
  int n, k;
  cin >> n >> k;

  int p;
  int max_dist = 0;
  char alphabet;
  for (int i = 0; i < n; i++) {
    cin >> p >> alphabet;
    max_dist = max(max_dist, p);
    if (alphabet == 'G') {
      arr[p] = 1;
      ans+=1;
    } else if (alphabet == 'H') {
      arr[p] = 2;
      ans+=2;
    }
  }

  if (max_dist < k) {
    cout << ans;
    return 0;
  }

  int max_point = 0;
  for (int i = 1; i <= max_dist - k; i++) {
    int point = 0;
    for (int j = i; j <= i + k; j++) {
      point += arr[j];
    }
    max_point = max(point, max_point);

  }


  cout << max_point;

  return 0;
}
