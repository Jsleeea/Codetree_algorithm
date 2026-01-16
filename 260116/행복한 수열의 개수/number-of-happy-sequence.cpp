#include <iostream>
using namespace std;

int n, m;

int arr[100][100];
int check[100];
int cnt = 0;

bool is_happy_num(int *x) { // true/false, check 초기화
  bool is_happy = false;

  int continuous = 0;

  int prev = x[0];

  for (int i = 0; i < n; i++) {
    int cur = x[i];

    if (cur == prev) {
      continuous++;
    }else {
      continuous = 1;
    }

    if (continuous == m) {
      is_happy = true;
      break;
    }

    prev = cur;
  }

  for (int i = 0; i < n; i++) { // 초기화
    x[i] = 0;
  }

  return is_happy;
}

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      check[j] = arr[i][j];
    }
    if (is_happy_num(check)) {
      cnt++;
    }
  }

  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      check[i] = arr[i][j];
    }
    if (is_happy_num(check)) {
      cnt++;
    }
  }

  cout << cnt;
  return 0;
}