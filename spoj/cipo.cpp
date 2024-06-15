#include <bits/stdc++.h>

#ifdef DEBUG
#define PRINT(s) std::cout << s << '\n';
#endif

using namespace std;
using pii = pair<int, int>;
using ull = unsigned long long;
using ll = long long;

ull prim(vector<vector<pii>> &adj, vector<bool> &visited, int og,
         int &num_visited) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  ull cost = 0;
  // vector<bool> visited(adj.size(), false);

  visited[og] = true;
  int n = adj.size();

  for (auto &[w, v] : adj[og])
    if (!visited[v])
      pq.push({w, v});

  while (!pq.empty() && num_visited != n - 1) {
    auto [w, u] = pq.top();
    pq.pop();

    if (visited[u])
      continue;

    visited[u] = true;
    num_visited++;
    cost += w;

    for (auto &[wv, v] : adj[u])
      if (!visited[v])
        pq.push({wv, v});
  }

  return cost;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int k = 0;
  int n, m;

  while (cin >> n >> m) {
    vector<vector<pii>> adj(n);

    while (m--) {
      int u, v, w;
      cin >> u >> v >> w;
      u--, v--;

      adj[u].push_back({w, v});
      adj[v].push_back({w, u});
    }

    ull ans = 0;
    vector<bool> visited(n, false);
    int num_visited = 0;

    for (int i = 0; i < n; ++i)
      if (!visited[i])
        ans += prim(adj, visited, i, num_visited);
    cout << "Instancia " << ++k << '\n' << ans << "\n\n";
  }
}
