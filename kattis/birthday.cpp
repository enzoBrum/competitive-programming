#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

bool dfs(int u, int p, vector<vector<int>>& adj, vector<char>& visited, vector<int>& tin, vector<int>& low, int& cnt) {
  low[u] = tin[u] = cnt++;
  visited[u] = true;
  
  int children = 0;
  for (auto& v : adj[u]) {
    if (v == p)
      continue;
    if (visited[v])
      low[u] = min(low[u], tin[v]);
    else {
      children++;
      if (dfs(v, u, adj, visited, tin, low, cnt))
        return true;
      
      if (low[v] > tin[u])
        return true;

      low[u] = min(low[u], low[v]);
    }
  }
  
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int p, c;
  while (cin >> p >> c && p && c) {
    vector<vector<int>> adj(p);
    vector<int> tin(p, 0), low(p);
    
    while (c--) {
      int u, v;
      cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    
    vector<char> visited(adj.size(), 0);
    int cnt = 0;
    
    bool suc = false;
    for (int i = 0; i < p && !suc; ++i)
      if (!visited[i])
        suc = dfs(i, -1, adj, visited, tin, low, cnt);

    cout << ( suc ? "Yes\n" : "No\n");
  }
}
