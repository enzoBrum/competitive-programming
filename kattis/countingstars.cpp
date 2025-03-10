#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<vector<char>> matrix;
vector<vector<char>> visited;
vector<pii> directions = {
  {1, 0},
  {-1, 0},
  {0, 1},
  {0, -1}
};

void dfs(int i, int j) {
  visited[i][j] = true;
  for (auto&[di, dj] : directions) {
    int fi = i + di, fj = j + dj;
    if (fi < 0 || fj < 0 || fi == matrix.size() || fj == matrix[0].size() || visited[fi][fj] || matrix[fi][fj] != '-')
      continue;
    dfs(fi, fj);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  int t = 1;
  while (cin >> n >> m) {
    matrix.assign(n, vector<char>(m));
    visited.assign(n, vector<char>(m, 0));
    
    int ans = 0;
    for (auto& row : matrix)
      for (auto& cell : row)
        cin >> cell;

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (!visited[i][j] && matrix[i][j] == '-')
          dfs(i, j), ans++;
    cout << "Case " << t++ << ": " << ans << '\n';
  }
}
