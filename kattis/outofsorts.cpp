#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ll n, m, a, c, x;
  cin >> n >> m >> a >> c >> x;

  vector<ll> sequence(n + 1);
  sequence[0] = x;

  for (int i = 1; i <= n; ++i)
    sequence[i] = (a * sequence[i - 1] + c) % m;

  int cnt = 0;
  for (auto &v : sequence)
    if (binary_search(all(sequence), v))
      cnt++;
  cout << cnt << '\n';
}
