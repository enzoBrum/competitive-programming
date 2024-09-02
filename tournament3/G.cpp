#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

/**
* distance(int n) {
*   int min_d = abs(vec[n-1] - vec[n]);
*   for (int i = 0; i < n; ++i) {
*     min_d = min(distance(n), )
*   }
* }
*
*
* 0 10 4 12
* 0 00 00 00
*
* 10 10 0 0 
*
*
*/

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<ll> vec(n+1);
  for (int i = 1; i <= n; ++i)
    cin >> vec[i];

  vector<vector<ll>> dp(n+1 , vector<ll>(n+1, 0ll));
  dp[1][0] = vec[1];
  for (int i = 2; i <= n; ++i) {
    dp[i][i-1] = 1e18;
    for (int j = 0; j < i-1; ++j) {
      dp[i][i-1] = min(dp[i][i-1], dp[i-1][j] + abs(vec[j] - vec[i])); // create TP at i-1. TP to j.
      dp[i][j] = dp[i-1][j] + abs(vec[i] - vec[i-1]); // come from i - 1. keep tp at j

    }
  }

  ll ans = 1e18;
  for (auto& v : dp.back())
    if (v)
      ans = min(ans, v);
  cout << ans << '\n';
}
