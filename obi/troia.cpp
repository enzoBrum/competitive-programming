#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  int ans = 0;
  vector<bool> visited(n, false);
  for (int i = 0; i < n; ++i) {
    if (visited[i])
      continue;
    queue<int> q;
    q.push(i);

    visited[i] = true;
    ans++;
    while (!q.empty()) {
      auto u = q.front();
      q.pop();

      for (auto &v : adj[u]) {
        if (visited[v])
          continue;
        visited[v] = true;
        q.push(v);
      }
    }
  }
  cout << ans << '\n';
}
