#include <algorithm>
#include <iostream>

using namespace std;

int n, m;
int map[200][200];

int max_val = 0;

bool in_range(int x, int y) { return 0 <= x && x < n && 0 <= y && y < m; }

int main() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < n; i++) { // 가로 막대기
    for (int j = 0; j < m - 2; j++) {
      int cnt = 0;
      for (int k = 0; k < 3; k++) {
        cnt += map[i][j + k];
      }
      max_val = max(cnt, max_val);
    }
  }

  for (int i = 0; i < n - 2; i++) { // 세로 막대기
    for (int j = 0; j < m; j++) {
      int cnt = 0;
      for (int k = 0; k < 3; k++) {
        cnt += map[i + k][j];
      }
      max_val = max(cnt, max_val);
    }
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < m - 1; j++) {
      int cnt = 0;
      for (int k = 0; k < 2; k++) {
        for (int l = 0; l < 2; l++) {
          cnt += map[i + k][j + l];
        }
      }
      max_val = max(cnt - map[i][j], max_val);
      max_val = max(cnt - map[i][j + 1], max_val);
      max_val = max(cnt - map[i + 1][j], max_val);
      max_val = max(cnt - map[i + 1][j + 1], max_val);
    }
  }

  cout << max_val;

  return 0;
}