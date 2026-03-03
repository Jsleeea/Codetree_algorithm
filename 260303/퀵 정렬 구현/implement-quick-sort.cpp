#include <algorithm>
#include <iostream>
using namespace std;

int arr[100001];

int partition(int left, int right) {
  int pivot = arr[right]; // 가장 오른쪽 원소를 피벗으로 설정
  int i = left - 1;       // '작은 원소 구역'의 끝 지점

  for (int j = left; j < right; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(arr[i], arr[j]);
    }
  }

  swap(arr[i + 1], arr[right]);

  return i + 1;
}

void quick_sort(int left, int right) {
  if (left < right) { // 정렬할 범위가 원소 1개 이하가 되면 종료.
    int pivot_idx = partition(left, right);

    quick_sort(left, pivot_idx - 1);
    quick_sort(pivot_idx + 1, right);
  }
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  quick_sort(0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }

  return 0;
}