#include <iostream>
#include <queue>

using namespace std;

int main(void) {
  priority_queue<int> pq;

  string command;

  int n;
  cin >> n;
  while (n--) {
    cin >> command;
    if (command == "push") {
      int a;
      cin >> a;
      pq.push(a);
    }else if (command == "pop") {
      cout << pq.top() << '\n';
      pq.pop();
    }else if (command == "size") {
      cout << pq.size() << '\n';
    }else if (command == "empty") {
      if (pq.empty()) {
        cout << 1 << '\n';
      }else {
        cout << 0 << '\n';
      }
    }else if (command == "top") {
      cout << pq.top() << '\n';
    }
  }

  return 0;
}