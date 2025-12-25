#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
  priority_queue<int, vector<int>, greater<int>> pq;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    pq.push(x);
  }

  int a, b, c;
  int sum = 0;

  for (int i = 0; i < n - 1; i++) {
    a = pq.top();
    pq.pop();
    b = pq.top();
    pq.pop();

    c = (a + b);

    sum += c;

    pq.push(c);

  }

  cout << sum;
  return 0;
}