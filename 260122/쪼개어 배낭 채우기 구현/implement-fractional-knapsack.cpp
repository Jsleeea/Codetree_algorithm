#include <algorithm>
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Stone {
  double weight;
  double value;
  double average_value;
};

bool cmp(Stone &a, Stone &b) { return a.average_value > b.average_value; }

vector<Stone> v;
double final_value = 0;
double remain_capacity = 0;

int main() {
  int n, m;
  cin >> n >> m;
  remain_capacity = m;

  while (n--) {
    Stone stone;
    cin >> stone.weight >> stone.value;
    stone.average_value = stone.value / stone.weight;

    v.push_back(stone);
  }

  sort(v.begin(), v.end(), cmp);

  for (int i = 0; i < v.size(); i++) {
    if (remain_capacity <= 0) {
      break;
    }
    if (remain_capacity >= v[i].weight) {
      remain_capacity -= v[i].weight;
      final_value += v[i].value;
    }else {
      final_value += v[i].average_value * remain_capacity;
      break;
    }
  }

  cout << fixed;
  cout.precision(3);

  cout << final_value;

  return 0;
}