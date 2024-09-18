#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  // f(R) = -aR^2 + bR + c
  // f'(R) = -2aR + b
  // 0 = -2aR + b
  // 2aR = b
  // R = b/2a

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    double best = -1e9;
    int ans = -1;
    for (int i = 1; i <= n; ++i) {
      double a, b, c;
      cin >> a >> b >> c;

      double r = b/(a*2.0);
      double val = -a*r*r + b*r + c;
      if (val > best)
        best = val, ans = i;
    }
    cout << ans << '\n';
  }
}
