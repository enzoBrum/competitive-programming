#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<ll> vec(n);
  for (auto &v : vec)
    cin >> v;

  ll ans = 0;
  for (int i = n - 2; i >= 0; --i) {
    if (!vec[i + 1]) {
      cout << "1\n";
      return 0;
    }

    if (vec[i] > vec[i + 1])
      ans += (vec[i] - vec[i + 1] + 1),
          vec[i] = vec[i] - (vec[i] - vec[i + 1]) - 1;
  }
  cout << ans << '\n';
}
