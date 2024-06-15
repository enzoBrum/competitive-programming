#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int bfs(vector<vector<int>> &adj, vector<int> &parents,
        vector<vector<int>> &capacity, int s, int t) {
  fill(parents.begin(), parents.end(), -1);
  parents[s] = -2;

  queue<pii> q;
  q.push({1e9, s});

  while (!q.empty()) {
    auto [flow, u] = q.front();
    q.pop();

    for (auto &v : adj[u]) {
      if (parents[v] != -1 || !capacity[u][v])
        continue;

      parents[v] = u;
      int new_flow = min(flow, capacity[u][v]);

      if (v == t)
        return new_flow;
      q.push({new_flow, v});
    }
  }
  return 0;
}

int edmonds_karp(vector<vector<int>> &adj, vector<vector<int>> &capacity, int s,
                 int t) {
  int n = adj.size();
  vector<int> parents(n, -1);

  int max_flow = 0;
  int flow;
  while ((flow = bfs(adj, parents, capacity, s, t)) > 0) {
    max_flow += flow;

    int cur = t;
    while (cur != s) {
      int prev = parents[cur];
      capacity[cur][prev] += flow;
      capacity[prev][cur] -= flow;
      cur = prev;
    }
  }

  return max_flow;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, m, k;
  int cnt = 0;
  while (cin >> n >> m >> k) {
    int size = n + m + 2;

    vector<vector<int>> adj(size);
    vector<vector<int>> capacity(size, vector<int>(size, 0));

    vector<int> affinity(n);
    for (auto &h : affinity)
      cin >> h;

    while (k--) {
      int horse, soldier;
      cin >> horse >> soldier;

      horse += m;

      adj[horse].push_back(soldier);
      adj[soldier].push_back(horse);

      capacity[soldier][horse] = 1;
    }

    for (int i = 1; i <= m; ++i) {
      adj[i].push_back(0);
      adj[0].push_back(i);
      capacity[0][i] = 1;
    }

    int last = size - 1;
    for (int i = m + 1; i <= n + m; ++i) {
      adj[i].push_back(last);
      adj[last].push_back(i);
      capacity[i][last] = affinity[i - (m + 1)];
    }

    // for (int i = 0; i < size; ++i) {
    //   cout << i << ": ";
    //   for (auto &j : adj[i])
    //     cout << j << ' ';
    //   cout << '\n';
    // }

    cout << "Instancia " << ++cnt << '\n'
         << edmonds_karp(adj, capacity, 0, last) << "\n\n";
  }
}
