#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    int best = -1, ans = -1;
    for (int i = 2; i <= n; ++i) {
      int curr = 0;
      int j = 1;

      while (i * j <= n) {
        curr += i * j;
        ++j;
      }

      if (best < curr) {
        best = curr;
        ans = i;
      }
    }

    cout << ans << '\n';
  }
}
