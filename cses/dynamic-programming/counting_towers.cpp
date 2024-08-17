#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  vector<int> dp(1e6 + 1), pref(1e6 + 1);
  dp[1] = pref[1] = 2;
  const int mod = 1e9 + 7;
  int calc = 1;
  while (t--) {
    int n;
    cin >> n;

    if (n <= calc) {
      cout << dp[n] << '\n';
      continue;
    }

    for (int i = calc + 1; i <= n; ++i) {
      dp[i] = (pref[i - 1] * pref[i - 1] + 1 + i) % mod;
      pref[i] = (pref[i - 1] + dp[i]) % mod;
      calc++;
    }

    cout << dp[n] << '\n';
  }
}
