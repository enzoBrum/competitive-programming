#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int dp[101][101];


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int p;
  cin >> p;
  for (int num = 0; num <= 100; ++num)
    dp[num][0] = dp[num][num - 1] = 1;
  
  for (int num = 2; num <= 100; ++num)
    for (int d = 1; d < num-1; ++d)
      dp[num][d] = ((dp[num-1][d] * (d+1)) + (dp[num-1][d-1] * (num-d))) % 1001113;

  while (p--) {
    int k, n, v;
    cin >> k >> n >> v;

    cout << k << ' ' << dp[n][v] << '\n';
  }
}