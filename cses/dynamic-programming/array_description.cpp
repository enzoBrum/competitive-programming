#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  cin >> n >> m;

  vector<int> vec(n);
  for (auto &v : vec)
    cin >> v;

  vector<vector<int>> dp(n, vector<int>(m + 1, 0));

  dp[0][vec[0]] = 1;
  if (vec[0] == 0)
    fill(dp[0].begin() + 1, dp[0].end(), 1);
  int mod = 1e9 + 7;
  for (int i = 1; i < n; ++i) {
    if (vec[i] != 0) {
      dp[i][vec[i]] = dp[i - 1][vec[i]];
      if (vec[i] < m)
        dp[i][vec[i]] += dp[i - 1][vec[i] + 1];

      dp[i][vec[i]] %= mod;
      dp[i][vec[i]] += dp[i - 1][vec[i] - 1];
      dp[i][vec[i]] %= mod;
      continue;
    }

    for (int j = 1; j <= m; ++j) {
      dp[i][j] = dp[i - 1][j];
      if (j > 1)
        dp[i][j] += dp[i - 1][j - 1];
      dp[i][j] %= mod;
      if (j < m)
        dp[i][j] += dp[i - 1][j + 1];
      dp[i][j] %= mod;
    }
  }
  int ans = 0;
  for (int j = 1; j <= m; ++j)
    ans = (ans + dp[n - 1][j]) % mod;
  cout << ans << '\n';
}
