#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int INF = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m, k;
  int a;

  while (cin >> n >> m >> a >> k && (n || m || a || k)) {
    vector<vector<pii>> adj(n);

    while (m--) {
      int u, v, w;
      cin >> u >> v >> w;
      u--, v--;
      adj[u].push_back({w, v});
      adj[v].push_back({w, u});
    }

    int unsafe_towns = 0;
    vector<int> d(n, INF);

    while (a--) {
      int b;
      cin >> b;

      b--;
      if (d[b] >= k)
        unsafe_towns++;
      d[b] = 0;

      priority_queue<pii, vector<pii>, greater<pii>> pq;
      pq.push({0, b});

      while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();

        if (w > d[u])
          continue;

        for (auto &[wv, v] : adj[u]) {
          if (d[v] <= d[u] + wv)
            continue;
          if (d[u] + wv >= k)
            continue;

          if (d[v] >= k)
            unsafe_towns++;

          d[v] = d[u] + wv;
          pq.push({d[v], v});
        }
      }
      cout << n - unsafe_towns << '\n';
    }
    cout << '\n';
  }
}
