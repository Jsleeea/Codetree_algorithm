#include <iostream>
using namespace std;

int main() {
  int r, c;
  cin >> r >> c;

  char arr[15][15];

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> arr[i][j];
    }
  }

  int cnt = 0;
  for (int i = 1; i < r - 1; i++) {
    for (int j = 1; j < c - 1; j++) {
      if (arr[i][j] != arr[0][0]) { // 첫 번째 이동 점
        for (int k = i + 1; k < r - 1; k++) {
          for (int l = j + 1; l < c - 1; l++) {
            if (arr[k][l] != arr[i][j]) {
              if (arr[k][l] != arr[r - 1][c - 1]) {
                cnt++;
              }
            }
          }
        }
      }
    }
  }

  cout << cnt;

  return 0;
}