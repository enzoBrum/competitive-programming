#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;

void bfs(vector<vector<int>> &adj, vector<bool> &visited,
         int u, int ignored = -1) {
  queue<int> q;

  q.push(u);
  visited[u] = true;
  int og_u = u;
  while (!q.empty()) {
    auto u = q.front();
    q.pop();

    for (auto& v : adj[u]) {
      if (visited[v] || v == ignored) continue;

      visited[v] = true;
      q.push(v);
    }
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<vector<int>> adj(n);
  vector<pii> ask_money(n);
  vector<vector<int>> in_vertices(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;

    ask_money[i] = {a, b};
    adj[a].push_back(i);
    adj[b].push_back(i);
  }

  vector<bool> lose_money(n, false);
  for (int i = 0; i < n; ++i) {
    vector<bool> visited(n, false), visited_a(n, false), visited_b(n, false);
    auto[a, b] = ask_money[i];
    bfs(adj, visited, i);
    bfs(adj, visited_a, a, i);
    bfs(adj, visited_b, b, i);

    for (int j = 0; j < n && !lose_money[i]; ++j) {
      if (visited_a[j] && visited_b[j] && visited[j])
        lose_money[i] = true;
    }
  }

  for (auto b : lose_money)
    cout << (b ? "Y" : "N");
  cout << '\n';
}
