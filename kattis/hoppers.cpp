#include <bits/stdc++.h>
#include <variant>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int UNVISITED = -1, BLACK = 1, WHITE = 0;

bool dfs(int u, int p, int cur_col, vector<vector<int>>& adj, vector<char>& colors) {
  stack<int> st;
  st.push(u);
  colors[u] = BLACK;

  bool bipartite = true;

  while (!st.empty()) {
    auto u = st.top(); st.pop();
    for (auto& v  : adj[u]) {
      if (colors[v] == colors[u])
        bipartite = false;
      else if (colors[v] == UNVISITED)
        st.push(v), colors[v] = 1 - colors[u];
    }
  }
  return bipartite;
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
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  vector<char> colors(n, UNVISITED);
  int CCs = 0;
  bool non_bipartite = false;
  for (int i = 0; i < n; ++i) {
    if (colors[i] != UNVISITED)
      continue;
    if (!dfs(i, -1, BLACK, adj, colors))
      non_bipartite = true;
    CCs++;
  }
  cout << (non_bipartite ? CCs - 1 : CCs) << '\n';
}
