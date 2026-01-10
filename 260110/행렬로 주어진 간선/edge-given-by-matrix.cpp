#include <iostream>
using namespace std;

int map[101][101];

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> map[i][j];
      if (i == j) {
        map[i][j] = 1;
      }
    }
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (map[i][k] == 1 && map[k][j] == 1) {
          map[i][j] = 1;
        }
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << map[i][j] << " ";
    }
    cout << '\n';
  }
  return 0;
}