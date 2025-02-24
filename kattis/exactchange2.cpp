#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int dp[20'001][101];
int coins[101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;

  while (t--) {
    memset(coins, -1, sizeof(coins));
    
    int p, n;
    cin >> p >> n;

    for (int i = 0; i < n; ++i)
      cin >> coins[i];

    for (int i = 0; i < n; ++i)
      dp[0][i] = 0;
    for (int i = 1; i < 20'000; ++i)
      dp[i][0] = 1e9;
        
    int ans;
    for (int i = 1; i <= 20'000; ++i) {
      for (int j = 1; j <= n; ++j)
        if (coins[j-1] <= i)
          dp[i][j] = min(dp[i][j-1], dp[i - coins[j-1]][j-1] + 1);
        else
          dp[i][j] = dp[i][j-1];
      
      if (i >= p && dp[i][n] != 1e9) {
        ans = i;
        break;
      }
    }
    
    cout << ans << ' ' << dp[ans][n] << '\n';
  }
}
