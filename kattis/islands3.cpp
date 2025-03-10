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
  vector<vector<char>> visited(n, vector<char>(m, 0));
  for (auto& row : matrix)
    for (auto& cell : row)
      cin >> cell;
  
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (visited[i][j])
        continue;
      if (matrix[i][j] != 'L')
        continue;
      
      queue<pii> q;
      q.push({i, j});
      visited[i][j] = true;
      
      ans++;
      while (!q.empty()) {
        auto[i, j] = q.front();
        q.pop();

        for (auto&[di, dj] : directions) {
          int fi = i + di, fj = j + dj;
          if (fi < 0 || fj < 0 || fi >= n || fj >= m || visited[fi][fj] || matrix[fi][fj] == 'W')
            continue;

          q.push({fi, fj});
          visited[fi][fj] = true;
        }
      }
    }
  }
  
  cout << ans << '\n';
  
}
