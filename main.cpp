#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

  vector<unordered_map<int, int>> tree;
struct SegmentTree {

  inline int left(int p) { return p * 2; }

  inline int right(int p) { return p * 2 + 1; }

  SegmentTree(vector<int> &vec) {
    n = vec.size();
    int sz = 4 * n;

    tree.assign(sz, {});
    lazy.assign(sz, 0);

    build(1, 0, n - 1, vec);
  }

  unordered_map<int, int> merge(const unordered_map<int, int> &a, const unordered_map<int, int> &b) {
    unordered_map<int, int> mp;
    mp = a;
    for (auto &[k, v] : b) {
      if (mp.find(k) == mp.end())
        mp[k] = v;
      else
        mp[k] += v;
    }
    return mp;
  }

  void build(int p, int l, int r, vector<int> &vec) {
    if (l == r) {
      if (tree[p].find(vec[l]) == tree[p].end())
        tree[p][vec[l]] = 1;
      else 
        tree[p][vec[l]]++;
      return;
    }

    int m = (l + r) / 2;
    build(left(p), l, m, vec);
    build(right(p), m + 1, r, vec);

    tree[p] = merge(tree[left(p)], tree[right(p)]);
    // cout << "p: " << p << '\n';
    // for (auto&[k, v] : tree[p])
    //   cout << k << " -> " << v << '\n';
    // cout << "=========\n";

  }

  void propagate(int p, int l, int r) {
    if (lazy[p] == 0)
      return;

    tree[p].clear();
    tree[p][lazy[p]] = r - l + 1;

    if (l != r)
      lazy[left(p)] = lazy[right(p)] = lazy[p];

    lazy[p] = 0;
  }

  unordered_map<int, int> query(int i, int j) { return query(1, 0, n - 1, i, j); }

  void update(int i, int j, int v) { update(1, 0, n - 1, i, j, v); }

  vector<int> lazy;
  unordered_map<int, int> default_mp;
  int n;

private:
  unordered_map<int, int> query(int p, int l, int r, int i, int j) {
    propagate(p, l, r);
    if (i > j) // valor impossível. merge() deve ignorá-lo
      return default_mp;
    if (l >= i && r <= j)
      return tree[p];

    int m = (l + r) / 2;
    return merge(query(left(p), l, m, i, min(m, j)),
                 query(right(p), m + 1, r, max(i, m + 1), j));
  }

  void update(int p, int l, int r, int i, int j, int v) {    
    propagate(p, l, r);
    if (i > j)
      return;
    if (l >= i && r <= j) {
      tree[p].clear();
      tree[p][v] = j - i + 1;
      lazy[p] = v;
      return;
    }

    int m = (l + r) / 2;
    update(left(p), l, m, i, min(j, m), v);
    update(right(p), m + 1, r, max(i, m + 1), j, v);
    tree[p] = merge(tree[left(p)], tree[right(p)]);
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

    auto result = seg.query(0, l - 1);
    // for (auto&[k, v] : result)
    //   cout << k << " -> " << v << '\n';

    ll s = result[p];

    ll m1 = (a + (s + b) * (s + b)) % l;
    ll m2 = (a + s * s) % l;

    // cout << m1 << ' ' << m2 << ' ' << x << "\n===========\n";

    seg.update(min(m1, m2), max(m1, m2), x);
  }

    // for (auto&[k, v] : tree[1])
    //   cout << k << " -> " << v << '\n';
  auto result = seg.query(0, l - 1);
  int ans = 0;

  

  for (auto &[k, v] : tree[1]) {
    ans = max(ans, v);
  }
  cout << ans << '\n';
}
