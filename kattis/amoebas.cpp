#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<pii> directions = {
  {1, 0},
  {1, 1},
  {1, -1},
  {0, 1},
  {0, -1},
  {-1, 0},
  {-1, 1},
  {-1, -1}
};

void dfs(int i, int j, vector<vector<char>>& matrix, vector<vector<char>>& visited, int n, int m) {
  visited[i][j] = true;
  for (auto&[di, dj] : directions) {
    int fi = i + di, fj = j + dj;
    if (fi < 0 || fj < 0 || fi >= n || fj >= m || matrix[fi][fj] != '#' || visited[fi][fj])
      continue;
    dfs(fi, fj, matrix, visited, n, m);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  vector<vector<char>> matrix(n, vector<char>(m));
  for (auto& row : matrix)
    for (auto& cell : row)
      cin >> cell;

  vector<vector<char>> visited(n, vector<char>(m, 0));
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (visited[i][j] || matrix[i][j] != '#')
        continue;
      ans++;
      dfs(i, j, matrix, visited, n, m);
    }
  }
  cout << ans << '\n';
}
