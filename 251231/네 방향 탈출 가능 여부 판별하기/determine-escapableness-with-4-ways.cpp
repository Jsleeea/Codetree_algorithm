#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

int n, m;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int map[100][100];

bool in_range(int mx, int my) {
  if (0 <= mx && mx < n && 0 <= my && my < m) {
    return true;
  }
  return false;
}

bool can_move(int mx, int my) {
  if (!in_range(mx, my)) {
    return false;
  }
  if (!map[mx][my]) {
    return false;
  }
  return true;
}

bool bfs(int x, int y) {
  queue<pair<int, int>> q;
  q.push(make_pair(0, 0));
  map[x][y] = 0;

  while (!q.empty()) {
    pair<int, int> temp = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      if (can_move(temp.first + dx[i], temp.second + dy[i])) {
        if (temp.first + dx[i] == n - 1 && temp.second + dy[i] == m - 1) {
          return true;
        }
        q.push(make_pair(temp.first + dx[i], temp.second + dy[i]));
        map[temp.first + dx[i]][temp.second + dy[i]] = 0;
      }
    }
  }

  return false;
};

int main(void) {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> map[i][j];
    }
  }

  if (bfs(0, 0)) {
    cout << 1;
  } else {
    cout << 0;
  }

  return 0;
}