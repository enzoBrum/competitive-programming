#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

void find_bridges(int u, int p, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, vector<char>& visited, vector<vector<bool>>& bridge,  int& cnt) {
  tin[u] = low[u] = cnt++;
  visited[u] = true;

  for (auto& v : adj[u]) {
    if (v == p)
      continue;
    if (visited[v])
      low[u] = min(low[u], tin[v]);
    else {
      find_bridges(v, u, adj, tin, low, visited, bridge, cnt);
      
      if (low[v] > tin[u])
        bridge[u][v] = bridge[v][u] = true;
      low[u] = min(low[u], low[v]);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n);
  vector<int> tin(n), low(n);
  vector<vector<bool>> bridges(n, vector<bool>(n, false));
  vector<char> visited(n, 0);

  while (m--) {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  int cnt = 0;
  find_bridges(0, -1, adj, tin, low, visited, bridges, cnt);
  
  visited.assign(n, 0);
  
  queue<int> q;
  q.push(0);

  visited[0] = true;
  int ans = 0;

  while (!q.empty()) {
    auto u = q.front();
    q.pop();

    ans++;

    for (auto& v : adj[u]) {
      if (visited[v] || bridges[u][v])
        continue;
      visited[v] = true;
      q.push(v);
    }
  }
  
  cout << ans << '\n';
}
