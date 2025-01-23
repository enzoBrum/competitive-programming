#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<int> coin_change(vector<int> &coins, int sum) {
  sort(all(coins));
  vector<vector<int>> dp(sum + 1, vector<int>(coins.size() + 1, 1e9));

  for (int i = 0; i <= coins.size(); ++i)
    dp[0][i] = 0;

  for (int i = 1; i <= sum; ++i)
    for (int j = 1; j <= coins.size(); j++)
      if (coins[j - 1] <= i)
        dp[i][j] = min(dp[i][j - 1], dp[i - coins[j - 1]][j - 1] + 1);
      else
        dp[i][j] = dp[i][j - 1];

  vector<int> ret(sum + 1);
  for (int i = 1; i <= sum; ++i) {
    int mn = 1e9;
    for (int j = 1; j <= coins.size(); ++j)
      mn = min(mn, dp[i][j]);
    ret[i] = mn;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int h;
  cin >> h;

  vector<int> hotdogs(h);
  for (auto &h : hotdogs)
    cin >> h;

  int b;
  cin >> b;
  vector<int> buns(b);
  for (auto &b : buns)
    cin >> b;

  int sum = min(accumulate(all(buns), 0), accumulate(all(hotdogs), 0));
  auto hotdogs_sums = coin_change(hotdogs, sum);
  auto buns_sums = coin_change(buns, sum);

  // for (int i = 0; i < sum; ++i)
  //   cout << "I: " << i << ' ' << hotdogs_sums[i] << endl;
  // cout << endl;
  // for (int i = 0; i < sum; ++i)
  //   cout << "I: " << i << ' ' << buns_sums[i] << endl;
  // cout << endl;

  int best = 1e9;
  for (int i = 1; i <= sum; ++i) {
    if (hotdogs_sums[i] < 1e9 && buns_sums[i] < 1e9 &&
        hotdogs_sums[i] + buns_sums[i] < best) {
      best = hotdogs_sums[i] + buns_sums[i];
    }
  }
  if (best < 1e9)
    cout << best << '\n';
  else
    cout << "impossible\n";
}
