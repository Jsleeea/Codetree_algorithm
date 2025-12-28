#include <iostream>
using namespace std;

int x, y;
//              N   E  S  W
int dir_x[4] = {0, 1, 0, -1};
int dir_y[4] = {1, 0, -1, 0};

int main(void) {
  int dir = 0; // 현재 방향: 북(N)

  string s;
  cin >> s;

  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'L') {
      dir = (dir + 3) % 4;
    } else if (s[i] == 'R') {
      dir = (dir + 1) % 4;
    } else if (s[i] == 'F') {
      x += dir_x[dir];
      y += dir_y[dir];
    }
  }

  cout << x << ' ' << y;

  return 0;
}