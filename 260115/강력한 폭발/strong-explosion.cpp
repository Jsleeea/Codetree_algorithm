#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n;
int bomb_count = 0;
int max_bomb_count = 0;

int map[20][20];

vector<pair<int, int>> v;
vector<int> num_arr;

int dx1[5] = {-2, -1, 0, 1, 2};
int dy1[5] = {0, 0, 0, 0, 0};

int dx2[5] = {-1, 0, 1, 0, 0};
int dy2[5] = {0, 0, 0, -1, 1};

int dx3[5] = {-1, -1, 0, 1, 1};
int dy3[5] = {-1, 1, 0, -1, 1};

bool in_range(int x, int y) {
  if (0 <= x && x < n && 0 <= y && y < n) {
    return true;
  }
  return false;
}

int arr[20][20];

void fill(int bomb_num, int x, int y) {

  if (bomb_num == 1) {
    for (int i = 0; i < 5; i++) {
      if (!in_range(x + dx1[i], y + dy1[i]) ||
          arr[x + dx1[i]][y + dy1[i]] == 1) {
        continue;
      }
      arr[x + dx1[i]][y + dy1[i]] = 1;
      bomb_count++;
    }
  } else if (bomb_num == 2) {
    for (int i = 0; i < 5; i++) {
      if (!in_range(x + dx2[i], y + dy2[i]) ||
          arr[x + dx2[i]][y + dy2[i]] == 1) {
        continue;
      }
      arr[x + dx2[i]][y + dy2[i]] = 1;
      bomb_count++;
    }
  } else if (bomb_num == 3) {
    for (int i = 0; i < 5; i++) {
      if (!in_range(x + dx3[i], y + dy3[i]) ||
          arr[x + dx3[i]][y + dy3[i]] == 1) {
        continue;
      }
      arr[x + dx3[i]][y + dy3[i]] = 1;
      bomb_count++;
    }
  }
}

void check() {
  bomb_count = 0;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      arr[i][j] = 0;
    }
  }

  for (int i = 0; i < v.size(); i++) {
    fill(num_arr[i], v[i].first, v[i].second);
  }
  max_bomb_count = max(max_bomb_count, bomb_count);
}

void choose(int num) {
  if (num > v.size()) {
    check();
    return;
  }

  for (int i = 1; i <= 3; i++) {
    num_arr.push_back(i);
    choose(num + 1);
    num_arr.pop_back();
  }
}

int main() {
  cin >> n;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> map[i][j];

      if (map[i][j] == 1) {
        v.push_back({i, j});
      }
    }
  }

  choose(1);

  cout << max_bomb_count;

  return 0;
}