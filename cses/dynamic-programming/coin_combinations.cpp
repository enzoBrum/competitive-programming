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

  vector<int> dp(x + 1, 0);
  dp[0] = 1;
  for (int i = 1; i <= x; ++i) {
    for (auto &c : coins) {
      if (i - c < 0)
        break;
      dp[i] += dp[i - c];
      dp[i] %= ((int)1e9 + 7);
    }
  }

  // for (auto &p : dp)
  //   cout << p << ' ';
  // cout << '\n';

  cout << dp[x] << '\n';
}
