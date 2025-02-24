#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int dp[1001][41];
int d[41];
int p[1001][41];

int N;


int main() {
  //ios::sync_with_stdio(0);
  //cin.tie(0);
  
  int t;
  cin >> t;

  while (t--) {
    cin >> N;
    memset(dp, 127, sizeof(dp));
    memset(p, -1, sizeof(p));
    
    for (int i = 0; i < N; ++i)
      cin >> d[i];
    
    dp[d[0]][0] = d[0];
    
    for (int i = 1; i < N; ++i) {
      for (int h = 0; h <= 1000; ++h) {
        if (dp[h][i-1] >= 1e9)
          continue;
        

        if (h+d[i] <= 1000 && dp[h+d[i]][i] > max(dp[h][i-1], h+d[i]))
          dp[h+d[i]][i] = max(dp[h][i-1], h+d[i]), p[h+d[i]][i] = h;
        if (h-d[i] >= 0 && dp[h-d[i]][i] > max(dp[h][i-1], h-d[i]))
          dp[h-d[i]][i] = max(dp[h][i-1], h-d[i]), p[h-d[i]][i] = h;
      }
      
    }
    
    if (dp[0][N-1] >= 1e9)
      cout << "IMPOSSIBLE\n";
    else {
      vector<char> ans;
      int cur_h = 0;
      int cur_i = N-1;

      while (cur_i > 0) {
        int prev_i = cur_i-1;
        int prev_h = p[cur_h][cur_i];

        ans.push_back(cur_h > prev_h ? 'U' : 'D');
        cur_h = prev_h;
        cur_i = prev_i;
      }
      
      ans.push_back('U');
      for (auto it = ans.rbegin(); it != ans.rend(); ++it)
        cout << *it;
      cout << '\n';
    }
  }
}
