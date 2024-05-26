#include <bits/stdc++.h>

#ifdef DEBUG
#define PRINT(s) std::cout << s << '\n';
#endif

using namespace std;
using pii = pair<int, int>;

void dfs(vector<vector<int>> &adj, vector<bool> &visited,
         vector<pii> &ask_money, int u, vector<bool> &lose_money) {
  visited[u] = true;
  int og_index = -1;

  auto &[ua, ub] = ask_money[u];

  if (visited[ua] || visited[ub])
    lose_money[u] = true;

  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i];
    if (visited[v])
      continue;
    else
      dfs(adj, visited, ask_money, v, lose_money);
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
  vector<int> in_vertices(n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;

    ask_money[i] = {a, b};
    adj[i].push_back(a);
    adj[i].push_back(b);
    in_vertices[a]++;
    in_vertices[b]++;
  }

  vector<bool> lose_money(n, false);
  for (int i = 0; i < n; ++i) {
    vector<bool> visited(n, false);
    dfs(adj, visited, ask_money, i, lose_money);
  }

  for (auto b : lose_money)
    cout << (b ? "Y" : "N");
  cout << '\n';
}
