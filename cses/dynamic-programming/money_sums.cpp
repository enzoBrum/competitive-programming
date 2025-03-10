#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

bool dp[(int)1e5+1][101];
int coins[101];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  for (int i = 0; i < n; ++i)
    cin >> coins[i+1], dp[0][i]=1;
  dp[0][n] = 1;

  int sum = accumulate(begin(coins), end(coins), 0);
  
  vector<int> ans;
  for (int s = 1; s <= sum; ++s) {
    for (int c = 1; c <= n; ++c)
      if (s - coins[c] >= 0)
        dp[s][c] = dp[s][c-1] || dp[s-coins[c]][c-1];
      else
        dp[s][c] = dp[s][c-1];

    if (dp[s][n])
      ans.push_back(s);
  }
  
  cout << ans.size() << '\n';
  for (auto& a : ans)
    cout << a << ' ';
  cout << endl;
}
