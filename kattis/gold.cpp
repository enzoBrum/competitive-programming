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

int ans = 0;

void dfs(int i, int j) {
  visited[i][j] = true;
  //cout << "VISITED (" << i << ", " << j << ") -> " << matrix[i][j] << '\n';
  if (matrix[i][j] == 'G')
    ans++;

  bool trap_nearby = false;
  for (auto&[di, dj] : directions) {
    int fi = i + di, fj = j + dj;
    if (fi < 0 || fj < 0 || fi == matrix.size() || fj == matrix[0].size())
      continue;

    if (matrix[fi][fj] == 'T')
      trap_nearby = true;
  }
  
  if (trap_nearby)
    return;

  for (auto&[di, dj] : directions) {
    int fi = i + di, fj = j + dj;
    if (fi < 0 || fj < 0 || fi == matrix.size() || fj == matrix[0].size() || visited[fi][fj] || matrix[fi][fj] == '#' || matrix[fi][fj] == 'T')
      continue;

    dfs(fi, fj);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> m >> n;
  matrix.assign(n, vector<char>(m));
  visited.assign(n, vector<char>(m, 0));
  
  ans = 0;
  int pi, pj;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      cin >> matrix[i][j];
      
      if (matrix[i][j] == 'P')
        pi = i, pj = j;
    }

  dfs(pi, pj);
  cout << ans << '\n';
}
