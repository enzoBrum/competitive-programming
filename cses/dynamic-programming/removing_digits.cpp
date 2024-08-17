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
 
  vector<int> dp(n + 1, 1e9);
 
  dp[n] = 0;
  for (int i = n; i > 0; --i) {
    int curr = i;
    while (curr) {
      int possible = curr % 10;
      if (i - possible >= 0)
        dp[i - possible] = min(dp[i - possible], dp[i] + 1);
      curr /= 10;
    }
  }
  cout << dp[0] << '\n';
}
