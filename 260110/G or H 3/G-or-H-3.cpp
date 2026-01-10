#include <algorithm>
#include <iostream>
using namespace std;

int arr[10001];

int main() {
  int n, k;
  cin >> n >> k;

  int p, max_dist;
  char alphabet;
  for (int i = 0; i < n; i++) {
    cin >> p >> alphabet;
    max_dist = max(max_dist, p);
    if (alphabet == 'G') {
      arr[p] = 1;
    } else if (alphabet == 'H') {
      arr[p] = 2;
    }
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