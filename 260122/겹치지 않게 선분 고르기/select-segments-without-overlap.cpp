#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int max_value = 0;
vector<pair<int, int>> segments;

void dfs(int idx, int last_end, int cnt) {
  if (idx == n) {
    max_value = max(max_value, cnt);
    return;
  }

  int left = segments[idx].first;

  if (last_end < left) {
    dfs(idx + 1, max(last_end, segments[idx].second), cnt + 1);
  }

  dfs(idx + 1, last_end, cnt);
}

int main() {
  cin >> n;
  segments.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> segments[i].first;
    cin >> segments[i].second;
  }

  sort(segments.begin(), segments.end());

  // idx, 끝점, cnt
  dfs(0, 0, 0);

  cout << max_value;

  return 0;
}