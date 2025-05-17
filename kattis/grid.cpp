#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<pii> directions = {
  {1, 0},
  {-1, 0},
  {0, 1},
  {0, -1}
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  vector<vector<char>> matrix(n, vector<char>(m));
  for (auto& r : matrix)
    for (auto& c : r)
      cin >> c;
  
  vector<vector<int>> adj(n*m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int c = matrix[i][j] - '0';
      for (auto&[di, dj] : directions) {
        int fi = i + di*c, fj = j + dj*c;
        if (!(fi >= 0 && fi < n && fj >= 0 && fj < m))
          continue;
        adj[i*m + j].push_back(fi*m + fj);
      }
    }
  }
  
  queue<pii> q;
  vector<bool> visited(n*m, false);
  q.push({0, 0});
  visited[0] = true;
  
  while (!q.empty()) {
    auto[d, u] = q.front();
    q.pop();

    if (u == n*m-1) {
      cout << d << '\n';
      return 0;
    }
    
    for (auto& v : adj[u]) {
      if (visited[v])
        continue;
      visited[v] = true;
      q.push({d+1, v});
    }
  }
  cout << "-1\n";
}
