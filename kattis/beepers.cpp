#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int dp[12][1 << 11];
int dist[12][12];
int N;

// mask -> 0 (visited), 1 (not visited)
int tsp(int u, int mask) {
  if (!mask) return dist[u][0];
  int& ans = dp[u][mask];
  
  if (ans != -1) return ans;
  
  ans = 2e9;
  int m = mask;

  while (m) {
    int v = __builtin_ctz(m);
    int two_pow = 1 << v;
    
    ans = min(ans, dist[u][v] + tsp(v, mask ^ two_pow));
    m -= two_pow;
  }
  
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;

  while (t--) {
    memset(dp, -1, sizeof(dp));
    int x, y;
    cin >> x >> y;

    int ox, oy;
    cin >> ox >> oy;

    int n;
    cin >> n;
    
    N = n+1;

    vector<pii> nodes(n+1);
    nodes[0] = {ox, oy};
    
    for (int i = 1; i <= n; ++i)
      cin >> nodes[i].first >> nodes[i].second;
    
    for (int i = 0; i <= n; ++i)
      for (int j = i; j <= n; ++j)
        dist[i][j] = dist[j][i] = abs(nodes[i].first - nodes[j].first) + abs(nodes[i].second - nodes[j].second);
    
    cout << tsp(0, (1 << N) - 1) << '\n';
      
  }
}
