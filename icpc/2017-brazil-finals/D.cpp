#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

struct SegmentTree {

  inline int left(int p) { return p * 2; }

  inline int right(int p) { return p * 2 + 1; }

  SegmentTree(vector<int> &vec) {
    n = vec.size();
    int sz = 4 * n;

    tree.resize(sz);
    lazy.resize(sz);
    build(1, 0, n - 1, vec);
  }

  map<int, int> merge(const map<int, int> &a, const map<int, int> &b) {
    map<int, int> mp;
    for (auto &[k, v] : a)
      mp[k] += v;
    for (auto &[k, v] : b)
      mp[k] += v;
    return mp;
  }

  void build(int p, int l, int r, vector<int> &vec) {
    if (l == r) {
      tree[p][l] = vec[l];
      return;
    }

    int m = (l + r) / 2;
    build(left(p), l, m, vec);
    build(right(p), m + 1, r, vec);

    tree[p] = merge(tree[left(p)], tree[right(p)]);
  }

  void propagate(int p, int l, int r) {
    if (lazy[p].size() == 0)
      return;

    tree[p] = lazy[p];

    if (l != r)
      lazy[left(p)] = lazy[right(p)] = lazy[p];

    lazy[p].clear();
  }

  map<int, int> query(int i, int j) { return query(1, 0, n - 1, i, j); }

  void update(int i, int j, int v) { update(1, 0, n - 1, i, j, v); }

  vector<map<int, int>> tree, lazy;
  int n;

private:
  map<int, int> query(int p, int l, int r, int i, int j) {
    propagate(p, l, r);
    if (i > j) // valor impossível. merge() deve ignorá-lo
      return {};
    if (l >= i && r <= j)
      return tree[p];

    int m = (l + r) / 2;
    return merge(query(left(p), l, m, i, min(m, j)),
                 query(right(p), m + 1, r, max(i, m + 1), j));
  }

  pair<map<int, int>, int> update(int p, int l, int r, int i, int j, int v) {
    if (l > r)
      return {map<int, int>(), tree[p][v]};
    if (l == i && r == j) {
      auto old_mp = tree[p];
      old_mp.erase(v);
      int old_sz = tree[p].size();
      tree[p].clear();
      tree[p][v] = old_sz;
      lazy[p] = tree[p];
      return {old_mp, old_sz};
    }

    propagate(p, l, r);
    int m = (l + r) / 2;
    auto [amp, asz] = update(left(p), l, m, i, min(j, m), v);
    auto [bmp, bsz] = update(right(p), m + 1, r, max(l, m + 1), j, v);

    for (auto &[k, v] : amp)
      tree[p][k] -= v;
    for (auto &[k, v] : bmp) {
      tree[p][k] -= v;
      amp[k] += v;
    }
    tree[p][v] = asz + bsz;
    return {amp, asz + bsz};
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll l, c, n;
  cin >> l >> c >> n;

  vector<int> og(l, 1);

  SegmentTree seg(og);
  for (int i = 0; i < n; ++i) {
    ll p, x, a, b;
    cin >> p >> x >> a >> b;

    auto result = seg.query(0, n - 1);
    ll s = result[p];

    ll r = (a + (s + b) * (s + b)) % l;
    l = (a + s * s) % l;

    seg.update(min(l, r), max(l, r), x);
  }

  auto result = seg.query(0, n - 1);
  int ans;

  for (auto &[k, v] : result) {
    ans = max(ans, v);
  }
  cout << ans << '\n';
}
