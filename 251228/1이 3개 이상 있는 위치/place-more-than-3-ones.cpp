#include <iostream>
using namespace std;

int n;

int arr[100][100];

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool inRange(int x, int y) {
  if (0 <= x && x <= n - 1 && 0 <= y && y <= n - 1) {
    return true;
  }
  return false;
}

int main() {
  cin >> n;

  int count = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {

      int cnt = 0;

      for (int d = 0; d < 4; d++) {
        if (inRange(i + dx[d], j + dy[d]) && arr[i + dx[d]][j + dy[d]] == 1) {
          cnt++;
        }
      }

      if (cnt >= 3) {
        count++;
      }
    }
  }

  cout << count;
  return 0;
}
