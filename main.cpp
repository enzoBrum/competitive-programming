#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<ll, ll>;

vector<unordered_set<ll>> memo;
vector<pii> blueprints;

bool solve(int i, ll cur_v, ll all_gcd) {
  cout << "(" << i << ", " << cur_v << ", " << all_gcd << ")\n";
  if (i == -1)
    return cur_v % all_gcd == 0;

  if (memo[i].count(cur_v))
    return false;

  ll a = cur_v;
  ll b = blueprints[i].first;

  bool res = solve(i - 1, (a + b) % all_gcd, all_gcd);
  if (res)
    return true;

  b = -b;
  res = solve(i - 1, (all_gcd + ((a + b) % all_gcd)) % all_gcd, all_gcd);
  if (res)
    return true;
  memo[i].insert(cur_v);
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  blueprints.assign(n, {0, 0});
  memo.assign(n, {});
  for (auto &[g, r] : blueprints)
    cin >> g >> r;

  ll all_gcd = blueprints[0].second;
  for (int i = 1; i < n; ++i)
    all_gcd = gcd(all_gcd, blueprints[i].second);

  if (n == 1) {
    cout << "N\n";
    return 0;
  }
  if (all_gcd == 1) {
    cout << "Y\n";
    return 0;
  }

  cout << (solve(n - 1, 0, all_gcd) ? "Y\n" : "N\n");
}
