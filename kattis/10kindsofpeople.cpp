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

void dfs(int i, int j, vector<vector<char>>& matrix, vector<vector<int>>& color, int cur_color, char allowed) {
  color[i][j] = cur_color;
  
  for (auto&[di, dj] : directions) {
    int fi = i + di, fj = j + dj;
    if (fi < 0 || fj < 0 || fi >= matrix.size() || fj >= matrix[0].size() || color[fi][fj] != -1 || matrix[fi][fj] != allowed)
      continue;
    dfs(fi, fj, matrix, color, cur_color, allowed);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;

  vector<vector<char>> matrix(n, vector<char>(m));
  vector<vector<int>> color(n, vector<int>(m, -1));
  
  for (auto& row : matrix)
    for (auto& cell : row)
      cin >> cell;

  int num;
  cin >> num;
  
  int cur_color = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (color[i][j] == -1)
        dfs(i, j, matrix, color, cur_color++, matrix[i][j]);
  
  //for (auto& row : color) {
  //  for (auto& cell : row)
  //    cout << cell << ' ';
  //  cout << '\n';
  //}

  while (num--) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;

    r1--, r2--, c1--, c2--;

    cout << (color[r1][c1] == color[r2][c2] ? matrix[r1][c1] == '1' ? "decimal\n" : "binary\n" : "neither\n");
  }
}
