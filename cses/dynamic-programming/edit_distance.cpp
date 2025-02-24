#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

//int memo[5001][5001];
int dp[5010][5010];
string a, b;

//int solve(int i, int j) {
//  // printf("(%d, %d) Comparing a[%d]=%c and b[%d]=%c\n", i, j, i, a[i], j,
//  // b[j]);
//
//  if (i < 0)
//    return j+1;
//  if (j < 0)
//    return i+1;
//  if (i == 0 && j == 0)
//    return a[i] != b[j];
//
//  if (memo[i][j] != -1)
//    return memo[i][j];
//
//  int ans =
//      min(min(min(solve(i, j - 1), solve(i - 1, j)), solve(i - 1, j - 1)) + 1,
//          a[i] == b[j] ? solve(i - 1, j - 1) : (int)1e9);
//
//  // printf("(%d, %d) ans: %d\n", i, j, ans);
//
//  return memo[i][j] = ans;
//}

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  memset(dp, 127, sizeof dp);

  cin >> a >> b;
  if (a.size() < b.size())
    swap(a, b);
  
  dp[0][0] = a[0] != b[0];
  for (int i = 0; i < a.size(); ++i) {
    for (int j = 0; j < b.size(); ++j) {
      if (a[i] == b[j]) 
        dp[i+1][j+1] = min(dp[i][j], dp[i+1][j+1]);
      else
        dp[i+1][j+1] = min(dp[i][j] + 1, dp[i+1][j+1]);
      
      dp[i+1][j] = min(dp[i+1][j], dp[i][j] + 1);
      dp[i][j+1] = min(dp[i][j+1], dp[i][j] + 1);
    }
  }
  cout << dp[a.size()-1][b.size()-1] << '\n';
}
