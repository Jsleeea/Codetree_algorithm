#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef pair<int, int> pii;

int n, m;

vector<pii> adj[501];
bool visited[501];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int u, v, w;
    cin >> u >> v >> w;

    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }

  priority_queue<pii, vector<pii>, greater<pii>> pq;

  pq.push({0, 1});

  int total_weight = 0;

  while (!pq.empty()) {
    int w = pq.top().first;
    int u = pq.top().second;
    pq.pop();

    if (visited[u]) {
      continue;
    }

    visited[u] = true;
    total_weight += w;

    for (pii edge : adj[u]) {
      int next_w = edge.first;
      int next_v = edge.second;


      if (!visited[next_v]) {
        pq.push({next_w, next_v});
      }
    }
  }

  cout << total_weight;

  return 0;
}