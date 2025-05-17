#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

using iii = tuple<int, int, int>;

vector<vector<pii>> prim(vector<vector<pii>> &adj) {
  priority_queue<iii, vector<iii>, greater<iii>> pq;
  pq.push({0, 0, -1});

  vector<bool> taken(adj.size(), 0);
  vector<vector<pii>> mst(adj.size());
  while (!pq.empty()) {
    auto [w, u, p] = pq.top();
    pq.pop();

    if (taken[u])
      continue;

    taken[u] = true;
    if (p != -1)
      mst[p].push_back({w, u});

    for (auto &[wv, v] : adj[u])
      if (!taken[v])
        pq.emplace(max(wv, w), v, u);
  }
  return mst;
}

pair<int, bool> dfs(int u, int target, vector<vector<pii>> &adj,
                    vector<bool> &visited) {
  visited[u] = true;
  if (u == target)
    return {0, true};
  for (auto &[w, v] : adj[u]) {
    if (visited[v])
      continue;

    auto [mx, found] = dfs(v, target, adj, visited);
    if (found)
      return {max(mx, w), true};
  }
  return {2e9, false};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> matrix(n, vector<int>(m));
  for (auto &row : matrix)
    for (auto &cell : row)
      cin >> cell;
  vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  vector<vector<pii>> adj(n * m + 2);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (auto &[di, dj] : directions) {
        int fi = i + di, fj = j + dj;
        if (fi < 0 || fj < 0 || fi >= n || fj >= m)
          continue;
        adj[i * m + j + 1].push_back(
            {max(matrix[i][j], matrix[fi][fj]), fi * m + fj + 1});
      }
    }
  }
  
  for (int i = 0; i < n; ++i)
    adj[0].push_back({matrix[i][0], i * m + 1}), adj[i*m+1].push_back({matrix[i][0], 0}), adj[i*m + m - 1].push_back({matrix[i][m-1], n*m}), adj[n*m].push_back({matrix[i][m-1], i*m + m - 1});

  auto mst = prim(adj);

  
  int ans = 1e9;
  vector<bool> visited(mst.size(), 0);
  ans = min(ans, dfs(0, n * m, mst, visited).first);
  //for (int i = 0; i < adj.size(); ++i) {
  //  for (int j = 0; j < adj[i].size(); ++j)
  //    cout << i << ' ' << adj[i][j].second << ' ' << adj[i][j].first << endl;
  //}

  cout << ans << '\n';
}
