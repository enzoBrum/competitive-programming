#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using iiii = tuple<ll, int, int, int>;

ll dijkstra(vector<vector<tuple<ll, int, int, int>>> &adj, int t) {
  vector<ll> d(adj.size(), 1e18);
  d[0] = t;

  priority_queue<iiii, vector<iiii>, greater<iiii>> pq;
  pq.push({t, 0, 0, 0});

  while (!pq.empty()) {
    auto [dist, u, x, y] = pq.top();
    pq.pop();

    if (dist != d[u])
      continue;

    for (auto& [w, v, vx, vy] : adj[u]) {
      int time = dist % (vx + vy);
      if (time < vx)
        time = 0;
      else
        time = (vx + vy) - time;

      if (dist + time < d[v]) {
        d[v] = dist + time;
        pq.push({dist + time, v, vx, vy});
      }
    }
  }
  return d.back();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  ll t;
  cin >> n >> m >> t;

  vector<vector<tuple<ll, int, int, int>>> adj(n);
  vector<int> topen(m), tclosed(m);
  for (int i = 0; i < m; ++i) {
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    a--, b--;

    int time = (x + y) % t;
    if (time < x)
      time = 0;
    else
      time = (x+y) - time;

    adj[a].push_back({time, b, x, y});
    adj[b].push_back({time, a, x, y});
  }

  cout << dijkstra(adj, t) << '\n';
}
