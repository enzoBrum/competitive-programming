#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int dp[(int)5e6 + 1];
int coins[201];

int N;

void dp_coin_change() {
  for (int i = 1; i <= 5e6; ++i)
    for (int j = 0; j < N; ++j)
      if (coins[j] <= i)
        dp[i] = min(dp[i], dp[i - coins[j]] + 1);
}

int greedy_coin_change(int v) {
  int ans = 0;

  while (v) {
    auto it = upper_bound(begin(coins), begin(coins) + N, v);
    
    if (it ==  begin(coins))
      return -1;
    
    it--;
    
    ans += v / *it;
    v = v % *it;
  }
  return ans;
}

int main() {
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  
  memset(dp, 1, sizeof(dp));
  dp[0] = 0;
  
  cin >> N;
  for (int i = 0; i < N; ++i)
    cin >> coins[i];
  sort(begin(coins), begin(coins) + N);

  dp_coin_change();

  bool canonical = true;
  for (int i = 0; i <= 5e6 && canonical; ++i)
    canonical = canonical && dp[i] == greedy_coin_change(i);
  cout << (canonical ? "canonical" : "non-canonical") << '\n';
}
