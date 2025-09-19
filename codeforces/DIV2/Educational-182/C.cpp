#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int INF = 1e9;
ll INFL = 1e18;

int dp[100][2];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    memset(dp, 0, sizeof dp);
    vector<int> vec1(n), vec2(n);
    for (auto& v : vec1)
      cin >> v;
    for (auto& v : vec2)
      cin >> v;

    dp[0][0] = dp[0][1] = 1;
    int mod = 998244353;

    for (int i = 1; i < n; ++i) {
      if (vec1[i] >= vec1[i-1] && vec2[i] >= vec2[i-1]) {
        dp[i][0] = dp[i-1][0];
        dp[i][1] = dp[i-1][1];
      }
      if (vec2[i] >= vec1[i-1] && vec1[i] >= vec2[i-1]) {
        dp[i][0] = (dp[i][0] + dp[i-1][1]) % mod;
        dp[i][1] = (dp[i][1] + dp[i-1][0]) % mod;
      }
    }

    cout << (dp[n-1][0] + dp[n-1][1]) % mod << '\n';
  }
}
