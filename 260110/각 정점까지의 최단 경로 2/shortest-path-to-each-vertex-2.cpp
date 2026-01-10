#include <algorithm>
#include <iostream>

using namespace std;

#define INF 1e9

int map[101][101];

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      map[i][j] = INF;
      if (i == j) {
        map[i][j] = 0;
      }
    }
  }

  int from, to, weight;
  for (int i = 0; i < m; i++) { // 두 정점에 대한 간선이 여려개 존재가능
    cin >> from >> to >> weight;
    map[from][to] = min(map[from][to], weight);
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (map[i][j] == INF) {
        cout << -1 << ' ';
      } else {
        cout << map[i][j] << ' ';
      }
    }
    cout << '\n';
  }
  return 0;
}