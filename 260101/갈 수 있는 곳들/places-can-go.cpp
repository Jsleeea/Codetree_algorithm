#include <iostream>
#include <queue>
using namespace std;

struct Point {
  int x;
  int y;
};

queue<Point> q;

int n, k;
int map[100][100];
int my_count = 0;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool in_range(int x, int y) {
  if (0 <= x && x < n && 0 <= y && y < n) {
    return true;
  }
  return false;
}

bool can_go(int mx, int my) {
  if (!in_range(mx, my)) {
    return false;
  }
  if (map[mx][my] != 0) {
    return false;
  }
  return true;
}

void bfs() {
  while (!q.empty()) {
    Point p = q.front();
    q.pop();

    for (int i = 0; i < 4; i++) {
      int mx = p.x + dx[i];
      int my = p.y + dy[i];
      if (can_go(mx, my)) {
        q.push({mx,my});
        map[mx][my] = 1;
        my_count++;
      }
    }
  }
}

int main() {
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];
    }
  }

  for (int i = 0; i < k; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    q.push({x, y});
    map[x][y] = 1;
    my_count++;
  }

  bfs();

  cout << my_count;

  return 0;
}