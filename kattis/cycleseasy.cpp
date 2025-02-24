#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int dp[1 << 11][11];
int d[11][11];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int tt;
  cin >> tt;

  for (int t = 1; t <= tt; ++t) {
    memset(dp, 0, sizeof(dp));
    memset(d, 1, sizeof(d));
    int n, k;
    cin >> n >> k;
    
    for (int i = 0; i < k; ++i) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      d[u][v] = d[v][u] = 0;
    }
    
    for (int u = 0; u < n; ++u)
      dp[1 << u][u] = 1;
    for (int u = 0; u < n; ++u)
      for (int v = u+1; v < n; ++v)
        if (d[u][v])
          dp[(1 << u) | (1 << v)][u] = dp[(1 << u) | (1 << v)][v] = 1;

    for (int mask = 0; mask < (1 << n); ++mask) {
      if (__builtin_popcount(mask) <= 2)
        continue;
      
      for (int i = 0; i < n; ++i) {
        if (!(mask & (1 << i)))
          continue;

        for (int j = 0; j < n; ++j) {
          if (!(mask & (1 << j)) || i == j)
            continue;

          dp[mask][j] += (d[i][j] ? dp[mask ^ (1 << j)][i] : -dp[mask ^ (1 << j)][i]);
          dp[mask][j] %= 9901;
        }
      }
    }
    
    cout << (dp[(1 << n) - 1][0] * 4951) % 9901 << '\n';
  }
}
