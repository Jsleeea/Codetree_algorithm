#include <iostream>
#include <queue>

using namespace std;

int main(void) {
  priority_queue<int> pq;

  int n, m;
  cin >> n >> m;

  while (n--) {
    int x;
    cin >> x;
    pq.push(x);
  }

  while (m--) {
    int x = pq.top();
    pq.pop();
    pq.push(x - 1);
  }

  cout << pq.top();
  return 0;
}