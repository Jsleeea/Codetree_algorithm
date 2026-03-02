#include <iostream>
using namespace std;

int arr[101];

void swap(int &a, int &b) {
  int temp = a;
  a = b;
  b = temp;
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for (int i = 1; i < n; i++) {
    for (int j = i; j >= 0; j--) {
      if (arr[j - 1] > arr[j]) {
        swap(arr[j], arr[j - 1]);
      } else {
        break;
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }

  return 0;
}
