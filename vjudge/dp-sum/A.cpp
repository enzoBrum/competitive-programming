#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int INF = 1e9;

ll dp[16][11][2];

ll solve(string& a, int n, bool lz, bool bound) {
  if (n == 0)
    return 0;
  if (dp[n][lz][bound] != -1)
    return dp[n][lz][bound];

  int limit = bound ? a[a.size() - n] - '0' : 9;
  ll ans = 0;
  for (int i = 0; i <= limit; ++i) {
    if (lz && i > ) 
  }
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);


}
