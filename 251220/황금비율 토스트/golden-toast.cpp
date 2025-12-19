#include <iostream>
#include <list>

using namespace std;

int main(void) {
  list<char> l;

  int n, m;
  cin >> n >> m;

  char k;

  while (n--) {
    cin >> k;
    l.push_back(k);
  }

  list<char>::iterator it = l.end()--;

  string cmd;

  while (m--) {
    cin >> cmd;
    if (cmd == "L") {
      if(it!= l.begin()){
        it--;
      }
    } else if (cmd == "R") {
      if (it != l.end()) {
        it++;
      }
    } else if (cmd == "D") {
      it = l.erase(it);
      it--;
    } else if (cmd == "P") {
      char c;
      cin >> c;
      l.insert(it, c);
    }
  }

  it = l.begin();
  while (it != l.end()) {
    cout << *it;
    it++;
  }

  return 0;
}