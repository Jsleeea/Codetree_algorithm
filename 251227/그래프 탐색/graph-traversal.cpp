#include <iostream>
using namespace std;

int n, m;
int graph[1001][1001];
bool visited[1001];

void dfs(int v) {
  visited[v] = true;
  for (int i = 1; i <= n; i++) {
    if (graph[v][i] == 1 && !visited[i]) {
      dfs(i);
    }
  }
}

  int main() {
    cin >> n >> m;

    while (m--) {
      int x, y;
      cin >> x >> y;
      graph[x][y] = 1;
      graph[y][x] = 1;
    }

    dfs(1);

    int count = 0;
    for (int i = 2; i <= n; i++) {
      if (visited[i] == true) {
        count++;
      }
    }
    cout << count;

    return 0;
  }