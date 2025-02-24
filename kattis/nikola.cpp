#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int dp[1001][1001];
int costs[1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  for (int i =0 ; i < n; ++i)
    cin >> costs[i];

  memset(dp, -1, sizeof(dp));
  
  dp[1][0] = 0;
  for (int pos = 1; pos <= n; ++pos) {
    for (int last_jump = 0; last_jump <= n; ++last_jump) {
      
    }
  }
}
