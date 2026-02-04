#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int ans = 0;

int uf[10001][2];

struct Point {
  int a;
  int b;
  int weight;
};

bool cmp(const Point &a, const Point &b) { return a.weight < b.weight; }

int find(int a) {
  if (uf[a][0] == a) {
    return a;
  }

  int parent = find(uf[a][0]);
  uf[a][0] = parent;
  return parent;
}

void uni(int a, int b) {
  int A = find(a);
  int B = find(b);

  uf[A][0] = B;
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    char c;
    cin >> c;

    uf[i][0] = i;

    if (c == 'a') {
      uf[i][1] = 0;
    } else {
      uf[i][1] = 1;
    }
  }

  vector<Point> v;

  for (int i = 0; i < m; i++) {
    int a, b, weight;
    cin >> a >> b >> weight;

    Point p;
    p.a = a;
    p.b = b;
    p.weight = weight;

    v.push_back(p);
  }

  sort(v.begin(), v.end(), cmp);

  for (int i = 0; i < m; i++) {
    if (uf[v[i].a][1] == uf[v[i].b][1]) {
      continue;
    }
    if (find(uf[v[i].a][0]) == find(uf[v[i].b][0])) {
      continue;
    }
    uni(v[i].a, v[i].b);
    ans += v[i].weight;
  }

  int check = find(1);
  for (int i = 2; i <= n; i++) {
    if (find(i) != check) {
      ans = -1;
    }
  }

  cout << ans;

  return 0;
}