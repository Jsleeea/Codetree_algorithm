#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int arr[25][25];
int num_of_vil = 0;
int my_count = 0;
vector<int> people;
//           D  R
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

bool in_range(int x, int y) {
  if (0 <= x && x < n && 0 <= y && y < n) {
    return true;
  }
  return false;
}

bool can_go(int x, int y) {
  if (!in_range(x, y)) {
    return false;
  }
  if (arr[x][y] == 0) {
    return false;
  }
  return true;
}

void dfs(int x, int y) { // 마을 별 사람수 return
  arr[x][y] = 0;         // visited
  my_count++;
  for (int i = 0; i < 4; i++) {
    int mx = x + dx[i];
    int my = y + dy[i];
    if (can_go(mx, my)) {
      dfs(mx, my);
    }
  }
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      my_count = 0;
      if (arr[i][j] == 1) {
        dfs(i, j);
        people.push_back(my_count);
        num_of_vil++;
      }
    }
  }

  sort(people.begin(), people.end());

  cout << num_of_vil << '\n';
  for (int i = 0; i < people.size(); i++) {
    cout << people[i] << '\n';
  }
  return 0;
}