#include <iostream>
using namespace std;

int arr[100001];
int tmp[100001];

void merge(int left, int mid, int right) {
  int i = left;      // 왼쪽 배열의 시작 index
  int j = mid + 1;   // 오른쪽 배열의 시작 index
  int k = left;      // 임시 배열에 값을 넣기 시작할 index

  while (i <= mid && j <= right) {
    if (arr[i] < arr[j]) {
      tmp[k++] = arr[i++];
    } else {
      tmp[k++] = arr[j++];
    }
  }

  while (i <= mid) {  // 만약 왼쪽 배열이 다 안넣어지고 남아있다면
    tmp[k++] = arr[i++];
  }

  while (j <= right) {  // 만약 오른쪽 배열이 다 안넣어지고 남아있다면
    tmp[k++] = arr[j++];
  }

  for (int idx = left; idx <= right; idx++) {
    arr[idx] = tmp[idx];
  }
}


void merge_sort(int left, int right) {
  if (left >= right) { // 원소가 1개 남을때까지 쪼개기
    return;
  }

  int mid = (left + right) / 2;

  merge_sort(left, mid);
  merge_sort(mid + 1, right);

  merge(left, mid, right);
}

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  merge_sort(0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << arr[i] << ' ';
  }

  return 0;
}