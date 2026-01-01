#include <algorithm>
#include <iostream>

using namespace std;

int my_min = 100000000;

int my_abs(int x) {
  if (x < 0) {
    return -x;
  }
  return x;
}

int main() {
  int n;
  cin >> n;

  int arr[100];

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      sum += (my_abs(i - j) * arr[j]);
    }
    my_min = min(sum , my_min);
  }

  cout << my_min;

  return 0;
}