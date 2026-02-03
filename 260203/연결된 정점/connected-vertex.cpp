#include <iostream>
#include <vector>
using namespace std;

int uf[100001];
int sz[100001];

int find(int a) {
  if (a == uf[a]) {
    return a;
  }

  int root_node = find(uf[a]);
  uf[a] = root_node;
  return root_node;
}

void uni(int a, int b) {
  int A = find(a);
  int B = find(b);

  if (A == B) {
    return;
  }

  uf[A] = B; // B밑에다가 A 붙임
  sz[B] += sz[A];
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    uf[i] = i;
    sz[i] = 1;
  }

  while (m--) {
    char c;
    cin >> c;
    if (c == 'x') {
      int a, b;
      cin >> a >> b;
      uni(a, b);
    } else if (c == 'y') {
      int a;
      cin >> a;

      cout << sz[find(a)] << '\n';
    }
  }

  return 0;
}