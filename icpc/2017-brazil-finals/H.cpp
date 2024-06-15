#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int a, b, c;
  int d, e, f;
  cin >> a >> b >> c >> d >> e >> f;

  int ans = max(d - a, 0) + max(e - b, 0) + max(f - c, 0);
  cout << ans << '\n';
}
