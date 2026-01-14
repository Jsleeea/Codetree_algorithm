#include <algorithm>
#include <iostream>
using namespace std;

int min_distance = 1000000;

int dist(int x1, int x2, int y1, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int arr[100][2];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i][0] >> arr[i][1];
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      min_distance =
          min(dist(arr[i][0], arr[j][0], arr[i][1], arr[j][1]), min_distance);
    }
  }

  cout << min_distance;

  return 0;
}