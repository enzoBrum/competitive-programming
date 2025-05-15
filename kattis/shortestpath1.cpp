#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int INF = 1e9;

void dijkstra(int s, vector<vector<pii>> &adj, vector<int> &d) {

  priority_queue<pii, vector<pii>, greater<pii>> pq;
  pq.push({0, s});
  d[s] = 0;
  while (!pq.empty()) {
    auto [du, u] = pq.top();
    pq.pop();

    if (du > d[u])
      continue;

    for (auto &[wv, v] : adj[u]) {
      if (d[v] <= d[u] + wv)
        continue;
      d[v] = d[u] + wv;
      pq.push({d[v], v});
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, q, s;
  while (1) {
    cin >> n >> m >> q >> s;
    if (!n && !m && !q && !s)
      break;
    vector<vector<pii>> adj(n);
    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({w, v});
    }

    vector<int> d(n, INF);
    dijkstra(s, adj, d);

    for (int i = 0; i < q; ++i) {
      int v;
      cin >> v;

      if (d[v] == INF)
        cout << "Impossible\n";
      else
        cout << d[v] << '\n';
    }
    cout << '\n';
  }
}
