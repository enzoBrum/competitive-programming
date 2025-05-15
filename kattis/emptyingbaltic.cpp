#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int INF = 1e9;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int h, w;
  cin >> h >> w;

  vector<vector<int>> matrix(h, vector<int>(w));
  for (auto &row : matrix)
    for (auto &cell : row)
      cin >> cell;

  using iii = tuple<int, int, int>;
  priority_queue<iii, vector<iii>, greater<iii>> pq;

  vector<vector<int>> d(h, vector<int>(w, 0));

  int i, j;
  cin >> i >> j;
  i--, j--;
  d[i][j] = matrix[i][j];
  pq.push({d[i][j], i, j});

  while (!pq.empty()) {
    auto [dist, i, j] = pq.top();
    pq.pop();

    if (dist > d[i][j])
      continue;

    for (int di = -1; di < 2; ++di) {
      for (int dj = -1; dj < 2; ++dj) {
        if (!di && !dj)
          continue;
        int fi = i + di, fj = j + dj;

        if (fi < 0 || fj < 0 || fi >= h || fj >= w || matrix[fi][fj] >= 0)
          continue;

        int new_h = max(d[i][j], matrix[fi][fj]);
        if (new_h < d[fi][fj])
          d[fi][fj] = new_h, pq.push({new_h, fi, fj});
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < h; ++i)
    for (int j = 0; j < w; ++j)
      if (matrix[i][j] < 0)
        ans += (-d[i][j]);
  cout << ans << '\n';
}
