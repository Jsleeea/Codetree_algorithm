#include <iostream>
#include <vector>
using namespace std;

int n, m, k;

int arr[100001];

int find(int a) { // 부모찾기
  if (arr[a] == a) {
    return a;
  }
  int root_node = find(arr[a]);
  arr[a] = root_node;
  return root_node;
}

void uni(int a, int b) {
  int A = find(a);
  int B = find(b);
  arr[A] = B;
}

int main() {
  cin >> n >> m >> k;

  for (int i = 1; i <= n; i++) {
    arr[i] = i;
  }

  while (m--) {
    int a, b;
    cin >> a >> b;
    uni(a, b);
  }

  vector<int> v;
  while (k--) {
    int x;
    cin >> x;
    v.push_back(x);
  }

  for (int i = 0; i < v.size() - 1; i++) {
    if (find(v[i]) != find(v[i + 1])) {
      cout << 0;
      return 0;
    }
  }

  cout << 1;

  return 0;
}