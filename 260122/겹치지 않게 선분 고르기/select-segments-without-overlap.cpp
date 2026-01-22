#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int n;
int max_value = 0;
vector<pair<int, int>> segments;

// last_end: 직전에 선택한 선분의 끝나는 시간
void dfs(int idx, int last_end, int cnt) {
  // 기저 조건: 모든 선분을 다 훑어봤을 때
  if (idx == n) {
    max_value = max(max_value, cnt);
    return;
  }

  // 1. 이번 선분을 "선택하는" 경우
  // 조건: 이번 선분의 시작점이 직전 선분의 끝점보다 커야 함
  if (segments[idx].first > last_end) {
    dfs(idx + 1, segments[idx].second, cnt + 1);
  }

  // 2. 이번 선분을 "선택하지 않고 건너뛰는" 경우
  // 언제든 건너뛸 수 있음 (last_end와 cnt는 그대로 유지)
  dfs(idx + 1, last_end, cnt);
}

int main() {
  cin >> n;
  segments.resize(n);

  for (int i = 0; i < n; i++) {
    cin >> segments[i].first;
    cin >> segments[i].second;
  }

  // 시작점 기준으로 정렬
  sort(segments.begin(), segments.end());

  // 0번째 인덱스부터, 마지막 끝점은 0(아무것도 안 골랐으므로), 개수는 0
  dfs(0, 0, 0);

  cout << max_value; // ++ 없이 그대로 출력

  return 0;
}