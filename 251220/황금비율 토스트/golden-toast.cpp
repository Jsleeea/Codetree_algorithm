#include <iostream>
#include <list>

using namespace std;

int main(void) {
  list<char> l;

  int n, m;
  cin >> n >> m;

  while (n--) {
    char k;
    cin >> k;
    l.push_back(k);
  }

  auto it = l.end(); // iterator

  while (m--) {
    string cmd;
    cin >> cmd;

    if (cmd == "L") {
      if (it != l.begin()) {
        it--;
      }
    } else if (cmd == "R") {
      if (it != l.end()) {
        it++;
      }
    } else if (cmd == "D") {
      if (it != l.end()) {
        it = l.erase(it);
      }
    } else if (cmd == "P") {
      char c;
      cin >> c;
      it = l.insert(it, c);
      ++it;
    }
  }

  it = l.begin();
  while (it != l.end()) {
    cout << *it;
    it++;
  }

  return 0;
}