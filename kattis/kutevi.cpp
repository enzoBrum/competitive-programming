#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

char dp[361];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, k;
  cin >> n >> k;

  vector<int> angles(n);
  for (auto& a : angles)
    cin >> a;

  dp[0] = 1;
  for (int i = 0; i < 360; ++i)
    for (int angle = 0; angle < 360; ++angle)
      for (auto& a : angles)
        dp[(angle + a) % 360] = max(dp[(angle + a) % 360], dp[angle]);
  
  while (k--) {
    int angle;
    cin >> angle;
    cout << (dp[angle] == 1 ? "YES" : "NO") << '\n';
  }
  
}
