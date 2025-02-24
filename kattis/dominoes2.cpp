#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<vector<int>> adj;
vector<bool> visited;
int ans;

void dfs(int u, int p) {
  visited[u] = true;
  ans++;

  for (auto& v : adj[u])
    if (v != p && !visited[v])
      dfs(v, u);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;

  while (t--) {
    int n, m, l;
    cin >> n >> m >> l;

    adj.assign(n, {});
    visited.assign(n, false);
    ans = 0;

    while (m--) {
      int u, v;
      cin >> u >> v;
      u--, v--;

      adj[u].push_back(v);
    }
    
    int og_l = l;
    while (l--) {
      int z;
      cin >> z;
      z--;

      if (visited[z])
        continue;
      dfs(z, -1);
    
    }
    
    cout << ans << '\n';
  }
  
}
