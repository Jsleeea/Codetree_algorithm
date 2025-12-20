#include <iostream>
using namespace std;

int main(void) {
  int n;
  cin >> n;

  int arr[100];

  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    arr[i] = k;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }

  return 0;
}