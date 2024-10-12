#include <algorithm>
#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  vector<pii> vec(n);
  for (auto&[l, r] : vec)
    cin >> l >> r;

  sort(all(vec), [](const pii& a, const pii& b) {
    return a.first != b.first ? a.first < b.first : a.second >= b.second;
  });

  int ans = 0;
  int limit = 0;

  for (auto&[l, r] : vec) {
    if (l > limit)
      ans++, limit = r;
    else
      limit = min(limit, r);
  }

  cout << ans << '\n';
}


