#include <iostream>
using namespace std;

int n;
int x, y;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main(void) {
  cin >> n;

  while (n--) {
    char c;
    int distance;

    cin >> c >> distance;

    if (c == 'W') {
      x += dx[0] * distance;
      y += dy[0] * distance;
    } else if (c == 'S') {
      x += dx[1] * distance;
      y += dy[1] * distance;
    } else if (c == 'N') {
      x += dx[2] * distance;
      y += dy[2] * distance;
    } else {
      x += dx[3] * distance;
      y += dy[3] * distance;
    }
  }

  cout << x << ' ' << y;
  return 0;
}