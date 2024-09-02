#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int q;
  cin >> q;

  while (q--) {
    int n, t;
    cin >> n >> t;

    if (t == 1) {
      cout << n << '\n';
      continue;
    }

    int ans = 0;
    int limit = t-1;
    for (int i = 1; i*i <= limit && i <= n; ++i) {
      if (limit % i)
        continue;

      ans++;
      int b = limit / i;
      if (b != i && b <= n)
        ans++;
    }
    cout << ans << '\n';
  }
}
