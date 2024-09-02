#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int p;
  cin >> p;

  while (p--) {
    int t;
    cin >> t;

    vector<int> seq(12);
    for (auto& s : seq)
      cin >> s;

    int begin = seq[0], cur_min = 1e9;
    int ans = 0;
    for (int k = 1; k <= 10; ++k) {
      for (int i = 1; i < 11 && i + k - 1 < 11; ++i) {
        int begin = seq[i-1];
        int cur_min = 1e9;
        for (int j = 0; j < k; ++j) {
          cur_min = min(cur_min, seq[i+j]);
        }
        int end = seq[i+k];
        if (cur_min > begin && cur_min > end)
          ans++;
      }
    }
    
    cout << t << ' ' << ans << '\n';
  }
}
