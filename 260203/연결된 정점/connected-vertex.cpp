#include <iostream>
using namespace std;

int uf[100001];
// int uf_count[100001];

int find(int a) { // 부모찾기, 연결
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
  uf[A] = B;
}

int main() {
  int n, m;
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    uf[i] = i;
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
      // cout << uf_count[find(a)] << '\n';
      int cnt = 0;
      for (int i = 1; i <= n; i++) {
        if (find(a) == find(i)) {
          cnt++;
        }
      }

      cout << cnt << '\n';
    }
  }

  return 0;
}