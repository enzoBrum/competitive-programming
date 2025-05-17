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
        pq.emplace(wv, v, u);
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
  vector<vector<pii>> adj(n * m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      for (auto &[di, dj] : directions) {
        int fi = i + di, fj = j + dj;
        if (fi < 0 || fj < 0 || fi >= n || fj >= m)
          continue;
        adj[i * m + j].push_back(
            {max(0, matrix[fi][fj] - matrix[i][j]), fi * m + fj});
      }
    }
  }

  auto mst = prim(adj);

  vector<bool> visited(mst.size(), 0);
  cout << dfs(0, n * m - 1, mst, visited).first << '\n';
}
