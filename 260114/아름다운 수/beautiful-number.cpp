#include <iostream>
#include <vector>

using namespace std;

int n, my_count;
vector<int> v;

void check() {
  int val = 0;
  int val_count = 0;

  for (int i = 0; i < n; i++) {
    if (val_count == 0) {
      val = val_count = v[i];
    }
    if (v[i] != val) {
      return;
    }
    val_count--;
  }

  if (val_count != 0) return;
  
  my_count++;
}

void choose(int num) {

  if (num > n) {
    check();
    return;
  }

  for (int i = 1; i <= 4; i++) {
    v.push_back(i);
    choose(num + 1);
    v.pop_back();
  }
}

int main() {
  cin >> n;

  choose(1);
  cout << my_count;

  return 0;
}
