#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

// one-indexed tree!!!
struct FenwickTree {
  FenwickTree(int m) { tr.assign(m + 1, 0); }

  inline int ls_one(int i) { return i & -i; }

  FenwickTree(const vector<int> &vec) {
    tr.assign(vec.size() + 1, 0);
    for (int i = 1; i <= vec.size(); ++i)
      update(i, vec[i]);
  }

  ll query(int j) {
    ll s = 0;
    for (; j; j -= ls_one(j))
      s = max(s, tr[j]);
    return s;
  }

  ll query(int l, int r) { return query(r) - query(r - 1); }

  void update(int i, ll v) {
    for (; i < tr.size(); i += ls_one(i))
      tr[i] = max(tr[i], v);
  }

  vector<ll> tr;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  auto cmp = [](const pii &a, const pii &b) {
    return a.first != b.first ? a.first < b.first : a.second > b.second;
  };
  map<pii, ll, decltype(cmp)> mp;

  set<ll> fortunes;
  unordered_map<ll, ll> fortune_map;

  ll n;
  cin >> n;

  while (n--) {
    ll b, f, d;
    cin >> b >> f >> d;

    if (mp.find({b, f}) == mp.end())
      mp[{b, f}] = d;
    else
      mp[{b, f}] += d;

    fortunes.insert(f);
  }

  for (auto &f : fortunes)
    fortune_map[f] = fortune_map.size() + 1;

  FenwickTree ft(mp.size());
  ll ans = 0;
  for (auto &[k, donation] : mp) {
    auto &[beauty, fortune] = k;
    ll idx = fortune_map[fortune];

    ll new_best = (ll)donation + ft.query(idx - 1);

    ft.update(idx, new_best);
    ans = max(ans, ft.query(idx));
  }

  cout << ans << '\n';
}
