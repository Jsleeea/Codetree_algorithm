#include <iostream>
using namespace std;

int N, M;
int arr[100][100];
int visited[100][100];

int dx[2] = {1, 0};
int dy[2] = {0, 1};

int x, y;

bool in_range(int x, int y) {
  if (0 <= x && x < N && 0 <= y && y < M) {
    return true;
  }
  return false;
}

bool can_go(int x, int y) {
  if (in_range(x, y) && arr[x][y] == 1 && visited[x][y] == 0) {
    return true;
  }
  return false;
}

bool dfs(int x, int y) { // n-1, m-1 방문하면 true return / else false return
  visited[x][y] = 1;
  if (x == N - 1 && y == M - 1) {
    return true;
  }

  for (int i = 0; i < 2; i++) {
    int mx = x + dx[i];
    int my = y + dy[i];

    if (can_go(mx, my)) {
      if (dfs(mx, my)) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> arr[i][j];
    }
  }

  if (dfs(0, 0)) {
    cout << 1;
  } else {
    cout << 0;
  }

  return 0;
}