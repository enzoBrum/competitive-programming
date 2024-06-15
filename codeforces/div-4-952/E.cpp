#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  // ios::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    ll x, y, z, k2;
    cin >> x >> y >> z >> k2;

    ll first = max(max(x, y), z);
    ll third = min(min(x, y), z);
    ll second = x != first && x != third ? x : y != first && y != third ? y : z;

    ll best = 0;
    for (ll i = 1; i <= k2 && i <= first; ++i) {
      for (ll j = 1; j <= i && j <= second; ++j) {
        ll k = k2 / (i * j);
        if (i * j * k != k2)
          continue;
        if (k > third)
          continue;

        best = max((first - i + 1) * (second - j + 1) * (third - k + 1), best);
      }
    }

    cout << best << '\n';
  }
}
