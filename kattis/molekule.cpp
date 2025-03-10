#include <bits/stdc++.h>
#include <variant>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int UNVISITED = -1, BLACK = 1, WHITE = 0;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  vector<vector<int>> adj(n);
  vector<pii> edges(n-1);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
    edges[i] = {u, v};
  }
  
  queue<pii> q;
  
  q.push({BLACK, 0});
  vector<int> colors(n, UNVISITED);
  colors[0] = BLACK;
  
  while (!q.empty()) {
    auto[color, u] = q.front(); q.pop();

    for (auto& v : adj[u]) {
      if (colors[v] != UNVISITED)
        continue;
      colors[v] = 1 - color;
      q.push({1 - color, v});
    }
  }
  
  for (auto&[u, v] : edges)
    cout << (colors[u] == BLACK && colors[v] == WHITE ? 1 : 0) << '\n';

}
