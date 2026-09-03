#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int> q;

int main() {
  cin >> n >> k;

  for (int i=0;i<n;i++) {
    q.push(i+1);
  }

  int temp;

  while (!q.empty()) {
    for (int i=0; i<k-1;i++) {
      temp = q.front();
      q.pop();
      q.push(temp);
    }
    cout << q.front() << ' ';
    q.pop();
  }

  return 0;
}