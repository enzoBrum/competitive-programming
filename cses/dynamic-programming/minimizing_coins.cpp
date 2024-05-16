#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (auto &c : coins)
    cin >> c;

  sort(coins.begin(), coins.end());

  vector<int> dp(x + 1, 1e9);
  dp[0] = 0;
  for (int i = 1; i <= x; ++i) {
    for (auto &c : coins) {
      if (i - c < 0)
        break;
      dp[i] = min(dp[i - c] + 1, dp[i]);
    }
  }

  // for (auto &p : dp)
  //   cout << p << ' ';
  // cout << '\n';

  cout << (dp[x] == 1e9 ? "-1\n" : to_string(dp.back()) + "\n");
}
