#include <algorithm>
#include <iostream>
using namespace std;

int coins;

int map[20][20];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < n - 2; j++) {

      int cnt = 0;
      for (int k = 0; k < 3; k++) {
        for (int l = 0; l < 3; l++) {
          if (map[i + k][j + l] == 1) {
            cnt++;
          }
        }
      }

      coins = max(coins, cnt);
    }
  }

  cout << coins;

  return 0;
}