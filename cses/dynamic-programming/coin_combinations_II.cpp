#include <bits/stdc++.h>
 
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  int n, x;
  cin >> n >> x;
 
  vector<int> coins(n), dp(x + 1);
  for (auto &c : coins)
    cin >> c;
  sort(coins.begin(), coins.end());
 
  dp[0] = 1;
  int mod = 1e9 + 7;
  for (int i = 0; i < n; ++i)
    for (int j = 1; j <= x; ++j)
      if (coins[i] <= j)
        dp[j] = (dp[j] + dp[j - coins[i]]) % mod;
 
  cout << dp.back() << '\n';
}
