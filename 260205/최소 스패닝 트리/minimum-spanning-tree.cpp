#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int total = 0;
int uf[10001];

int find(int a) {
  if (uf[a] == a) {
    return a;
  }
  int parent = find(uf[a]);
  uf[a] = parent;
  return parent;
}

void uni(int a, int b) {
  int A = find(a);
  int B = find(b);

  uf[A] = B;
}

struct Point {
  int a;
  int b;
  int weight;
};

bool cmp(const Point &a, const Point &b) { return a.weight < b.weight; }


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    uf[i] = i;
  }

  vector<Point> v;

  for (int i = 0; i < m; i++) {
    int a, b, w;
    cin >> a >> b >> w;

    Point p;
    p.a = a;
    p.b = b;
    p.weight = w;

    v.push_back(p);
  }

  sort(v.begin(), v.end(), cmp);

  for (int i = 0; i < m; i++) {
    int A = find(v[i].a);
    int B = find(v[i].b);

    if (A == B) {
      continue;
    } else {
      uni(A, B);
      total += v[i].weight;
    }
  }

  cout << total;
  return 0;
}