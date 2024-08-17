#include <bits/stdc++.h>
 
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
 
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
 
  int n;
  cin >> n;
 
  vector<vector<char>> board(n, vector<char>(n));
  for (auto &row : board)
    for (auto &cell : row)
      cin >> cell;
 
  vector<vector<int>> dp(n, vector<int>(n, 0));
  dp[0][0] = 1;
  int mod = 1e9 + 7;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (board[i][j] == '*')
        continue;
 
      if (i != n - 1 && board[i + 1][j] == '.')
        dp[i + 1][j] = (dp[i][j] + dp[i + 1][j]) % mod;
      if (j != n - 1 && board[i][j + 1] == '.')
        dp[i][j + 1] = (dp[i][j] + dp[i][j + 1]) % mod;
    }
  }
  cout << dp.back().back() << '\n';
}
