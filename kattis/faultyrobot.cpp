#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using pbi = pair<bool, int>;
using ll = long long;
using ull = unsigned long long;

void dfs(int u, vector<vector<pbi>>& adj, vector<pair<bool, bool>>& visited, set<int>& ans, bool used_non_forced) {
  if (used_non_forced)
    visited[u].first = true;
  else
    visited[u].second = true;

  bool found_forced = false;
  for (auto&[forced, v] : adj[u])
    if (forced)
      found_forced = true;
  
  if (!found_forced)
    ans.insert(u);

  for (auto&[forced, v] : adj[u]) {
    bool n_used_non_forced = !forced || used_non_forced;

    if ((!forced && used_non_forced) || (n_used_non_forced && visited[v].first) || (!n_used_non_forced && visited[v].second))
      continue;
    dfs(v, adj, visited, ans, !forced || used_non_forced);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  vector<vector<pbi>> adj(n);
  vector<pair<bool, bool>> visited(n);
  
  while (m--) {
    int u, v;
    cin >> u >> v;
    
    bool forced = u < 0;
    adj[abs(u) - 1].push_back({forced, v-1});
  }
  
  set<int> ans;
  dfs(0, adj, visited, ans, false);
  
  cout << ans.size() << '\n';
}
