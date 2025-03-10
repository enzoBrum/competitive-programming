#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

void kosaraju(int u, vector<vector<int>>& adj, vector<char>& visited, vector<int>& order) {
  visited[u] = true;
  for (auto& v : adj[u])
    if (!visited[v])
      kosaraju(v, adj, visited, order);
  order.push_back(u);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n), tadj(n);
    vector<char> visited(n, 0);
    vector<int> order;
    
    while (m--) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      adj[u].push_back(v);
      tadj[v].push_back(u);
    }
    
    for (int u = 0; u < n; ++u)
      if (!visited[u])
        kosaraju(u, adj, visited, order);
    fill(all(visited), false);
    
    int ans = 0;
    
    vector<int> scc_root(adj.size());
    vector<vector<int>> scc(adj.size());
    vector<int> scc_in_degree(adj.size());
    for (auto it = order.rbegin(); it != order.rend(); ++it)
      if (!visited[*it]) {
        vector<int> vec;
        kosaraju(*it, tadj, visited, vec);
        
        for (auto& v : vec)
          scc_root[v] = *it;
      }
    
    for (int u = 0; u < adj.size(); ++u)
      for (auto& v : adj[u])
        if (scc_root[v] != scc_root[u])
          scc[scc_root[u]].push_back(scc_root[v]), scc_in_degree[scc_root[v]] = 1;
    
    for (int u = 0; u < adj.size(); ++u)
      if (scc_root[u] == u && scc_in_degree[u] == 0)
        ans++;
    

    cout << ans << '\n';
  }
}
