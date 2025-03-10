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
    vector<int> roots(n, 0);
    vector<int> order;
    vector<int> in_degree(n), out_degree(n);

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
    
    reverse(all(order));
    int scc = 0;
    for (auto& u : order) {
      if (visited[u])
        continue;
      vector<int> vec;
      kosaraju(u, tadj, visited, vec);
      
      for (auto& v : vec)
        roots[v] = u;
      scc++;
    }
    
    for (int u = 0; u < n; ++u)
      for (auto v : adj[u])
        if (roots[u] != roots[v])
          out_degree[roots[u]]++, in_degree[roots[v]]++;
    
    int in_sum = 0, out_sum = 0;
    for (int u = 0; u < n; ++u)
      if (u == roots[u]) {
        if (!in_degree[u])
          in_sum++;
        if (!out_degree[u])
          out_sum++;
      }
    
    cout << (scc == 1 ? 0 : max(in_sum, out_sum)) << endl;

  }
}
