#include <algorithm>
#include <iostream>
using namespace std;

int uf[100001];

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

  uf[B] = A;
}

int main() {
  int n;
  cin >> n;

  for (int i = 1; i <= n; i++) {
    uf[i] = i;
  }

  for (int i = 0; i < n - 2; i++) {
    int a, b;
    cin >> a >> b;

    if (a > b) {
      int temp = a;
      a = b;
      b = temp;
    }

    uni(a, b);
  }

  int a = find(uf[1]);
  int b;
  for (int i=2;i<=n;i++) {
    if (find(uf[i]) != a) {
      b = find(uf[i]);
      break;
    }
  }

  cout << a << " " << b;

  return 0;
}