#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

bool dfs(int u, vector<vector<int>>& adj, vector<int>& visited, vector<int>& ts) {
  visited[u] = 0;
  for (auto& v : adj[u]) {
      if (visited[v] == 0)
        return false;
      else if (visited[v] == 1)
        continue;
      if (!dfs(v, adj, visited, ts))
        return false;
  }
  ts.push_back(u);
  visited[u] = 1;
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    adj[v].push_back(u);
  }
  
  vector<int> ts;
  vector<int> visited(n, -1);
  bool possible = true;
  for (int i = 0; i < n; ++i)
    if (visited[i] == -1)
      possible = possible && dfs(i, adj, visited, ts);
  if (!possible)
    cout << "IMPOSSIBLE\n";
  for (auto it = ts.begin(); it != ts.end(); ++it)
    cout << (*it + 1) << '\n';
}
