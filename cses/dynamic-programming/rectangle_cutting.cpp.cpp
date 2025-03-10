#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int dp[1001][1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //memset(memo, -1, sizeof memo);
  
  int a, b;
  cin >> a >> b;
  
  
  
  memset(dp, 63, sizeof dp);
  for (int i = 1; i <= min(a, b); ++i)
    dp[i][i] = 0;
  int mx = max(a, b);
  for (int i = 1; i <= mx; ++i) {
    for (int j = 1; j <= mx; ++j) {
      for (int w = i; w >= 1; --w) {
        //printf("dp[%d][%d]=min(dp[%d][%d]=%d, (dp[%d][%d]=%d + dp[%d][%d]=%d + 1)=%d)\n", w+i, j, w+i, j, dp[w+i][j], w, j, dp[w][j], i, j, dp[i][j], dp[w][j] + dp[i][j] + 1);
        dp[w + i][j] = min(dp[w+i][j], dp[w][j] + dp[i][j] + 1);
      }
      for (int h = j; h >= 1; --h) {
        //printf("dp[%d][%d]=min(dp[%d][%d]=%d, (dp[%d][%d]=%d + dp[%d][%d]=%d + 1)=%d)\n", i, j+h, i, j+h, dp[i][j+h], i, j, dp[i][j], i, h, dp[i][h], dp[i][j] + dp[i][h] + 1);
        dp[i][j+h] = min(dp[i][j+h], dp[i][j] + dp[i][h] + 1);
      }
    }
  }

  
  cout << dp[a][b] << '\n';
}