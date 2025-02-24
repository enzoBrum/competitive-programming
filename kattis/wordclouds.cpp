#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int dp[5001];



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, c;
  cin >> n >> c;

  vector<pii> boxes(n);
  for (auto&[w, h] : boxes)
    cin >> w >> h;
  
    memset(dp, 127, sizeof dp);
    
    dp[n-1] = boxes[n-1].second;
    dp[n] = 0;
    for (int i = n-2; i >= 0; --i) {
      int cur_w = boxes[i].first;
      int cur_h = boxes[i].second;

      for (int j = i+1; j < n; ++j) {
        if (cur_w + boxes[j].first > c) {
          dp[i] = min(dp[i], cur_h + dp[j]);
          break;
        }
        
        cur_w += boxes[j].first;
        int old_h = cur_h;
        cur_h = max(cur_h, boxes[j].second);
        dp[i] = min(dp[i], min(old_h + dp[j], cur_h + dp[j+1]));
      }
    }
    
    cout << dp[0] << '\n';
}