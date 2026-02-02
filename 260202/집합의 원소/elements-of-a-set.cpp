#include <iostream>
using namespace std;

int n, m;

int arr[100001];

int find(int a) { // 부모찾기
  if (a == arr[a]) {
    return a;
  }
  return find(arr[a]);
}

void uni(int a, int b) {
  int A = find(a);
  int B = find(b);

  arr[A] = B;
}

int main() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    arr[i] = i;
  }

  while (m--) {
    int choose, a, b;
    cin >> choose >> a >> b;

    if (choose == 0) { // uni
      uni(a, b);
    } else if (choose == 1) { // find
      int A = find(a);
      int B = find(b);
      if (A == B) {
        cout << 1 << '\n';
      } else {
        cout << 0 << '\n';
      }
    }
  }

  return 0;
}