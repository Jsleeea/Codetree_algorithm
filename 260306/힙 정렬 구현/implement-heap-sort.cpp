#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

void heapify(int n, int i) { // 잔여 합 크기, 현재 index
  int largest = i;
  int left = i * 2 + 1;
  int right = i * 2 + 2;

  if (left < n && arr[left] > arr[largest]) {
    largest = left;
  }

  if (right < n && arr[right] > arr[largest]) {
    largest = right;
  }

  if (largest != i) {
    swap(arr[i], arr[largest]);
    heapify(n, largest);
  }
}

void heapSort() {
  int n = arr.size();

  for (int i = n / 2 - 1; i >= 0; i--) {
    heapify(n, i);
  }

  for (int i = n - 1; i >= 0; i--) {
    swap(arr[0], arr[i]);
    heapify(i, 0);
  }
}

/*
     0
  1     2
3  4   5  6
*/

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.push_back(x);
  }

  heapSort();

  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }
  return 0;
}