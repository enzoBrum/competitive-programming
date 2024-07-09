#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int dijkstra(vector<vector<pair<int, int>>> &adj, int ou, int ov) {
  vector<int> d(adj.size(), 1e9);
  d[ou] = 0;

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, ou});

  while (!pq.empty()) {
    auto [w, u] = pq.top();
    pq.pop();

    if (w > d[u])
      continue;

    for (auto &[wv, v] : adj[u]) {
      if (d[u] + wv >= d[v] || (u == ou && v == ov) || (u == ov && v == ou))
        continue;

      d[v] = d[u] + wv;
      pq.push({d[v], v});
    }
  }

  return d[ov];
}

vector<vector<int>> floyd_warshall(vector<vector<pii>> &adj) {
  int n = adj.size();
  vector<vector<int>> d(n, vector<int>(n, 1e9));
  for (int i = 0; i < n; ++i)
    d[i][i] = 0;
  for (int i = 0; i < n; ++i)
    for (auto &[w, v] : adj[i])
      d[i][v] = d[v][i] = w;

  for (int k = 0; k < n; ++k)
    for (int u = 0; u < n; ++u)
      for (int v = 0; v < n; ++v)
        d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
  return d;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<pii>> adj(n);
  vector<tuple<int, int, int>> edges;

  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    u--, v--;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
    edges.push_back({u, v, w});
  }

  auto shortest_paths = floyd_warshall(adj);

  for (auto &[u, v, w] : edges) {
    if (w != shortest_paths[u][v]) {
      cout << shortest_paths[u][v] << '\n';
      continue;
    }

    auto d = dijkstra(adj, u, v);
    cout << (d == 1e9 ? -1 : d) << '\n';
  }
}
