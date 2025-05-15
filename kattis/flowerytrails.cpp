#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int INF = 1e9;

pair<vector<int>, vector<vector<pii>>> dijkstra(int s,
                                                vector<vector<pii>> &adj) {

  vector<int> d(adj.size(), INF);
  vector<vector<pii>> p(adj.size());
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, s});
  d[s] = 0;
  while (!pq.empty()) {
    auto [du, u] = pq.top();
    pq.pop();

    if (du > d[u])
      continue;

    for (auto &[wv, v] : adj[u]) {
      if (d[v] < d[u] + wv)
        continue;
      else if (d[v] == d[u] + wv)
        p[v].push_back({wv, u});
      else {
        d[v] = d[u] + wv, pq.push({d[u] + wv, v});
        p[v].clear();
        p[v].push_back({wv, u});
      }
    }
  }
  return {d, p};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<pii>> adj(n);
  while (m--) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }

  auto [d, p] = dijkstra(0, adj);

  vector<bool> visited(n, false);
  visited[n - 1] = true;

  int cur = n - 1;
  int ans = 0;
  queue<int> q;
  q.push(n - 1);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto &[w, v] : p[u]) {
      ans += w;
      if (visited[v])
        continue;
      visited[v] = true;
      q.push(v);
    }
  }
  cout << ans * 2 << '\n';
}
