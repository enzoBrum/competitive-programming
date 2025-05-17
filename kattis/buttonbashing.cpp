#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int dp[3601];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int tt;
  cin >> tt;
  while (tt--) {
    int n, m;
    cin >> n  >> m;

    vector<int> bt;
    while (n--) {
      int w;
      cin >> w;

      bt.push_back(w);
    }
    
    queue<int> q;
    vector<bool> visited(3600, false);
    
    q.push(0);
    visited[0] = true;
    vector<int> ans(3600, 1e9);
    ans[0] = 0;
    while (!q.empty()) {
      auto u = q.front();
      q.pop();
      for (int v : bt) {
        int nxt = max(0, min(3600, u + v));
        if (visited[nxt])
          continue;
        visited[nxt] = true;
        ans[nxt] = ans[u]+1;
        q.push(nxt);
      }
    }
    for (int i = m; i <= 3600; ++i)
      if (ans[i] < 10000) {
        cout << ans[i] << ' ' << i - m << '\n';
        break;
      }
  }
}