#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<pii> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int p;
  int INF = 1e9;
  while (cin >> p && p) {
    vector<vector<int>> d(2001, vector<int>(2001, INF));

    queue<pii> q;
    while (p--) {
      int i, j;
      cin >> i >> j;
      d[i][j] = 0;
      q.push({i, j});
    }
    cin >> p;
    while (p--) {
      int i, j;
      cin >> i >> j;
      d[i][j] = -1;
    }
    int ans = -1;
    while (!q.empty() && ans == -1) {
      auto [i, j] = q.front();
      q.pop();

      for (auto &[di, dj] : directions) {
        int fi = i + di, fj = j + dj;
        if (fi < 0 || fi >= 2001 || fj < 0 || fj >= 2001)
          continue;
        if (d[fi][fj] == -1) {
          ans = d[i][j] + 1;
          break;
        }
        if (d[fi][fj] != INF)
          continue;
        d[fi][fj] = d[i][j] + 1;
        q.push({fi, fj});
      }
    }

    cout << ans << '\n';
  }
}
