#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<vector<int>> adj;
vector<bool> visited;

void dfs(int u, int p) {
  visited[u] = true;

  for (auto& v : adj[u])
    if (v != p && !visited[v])
      dfs(v, u);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  adj.resize(n);
  visited.assign(n, false);

  while (m--) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  
  dfs(0, -1);

  bool all_visited = all_of(all(visited), [](bool b) {return b;});
  if (all_visited) {
    cout << "Connected\n";
    return 0;
  }
  for (int i = 0; i < n; ++i)
    if (!visited[i])
      cout << i+1 << '\n';
}
