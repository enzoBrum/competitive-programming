#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using pil = pair<int, ll>;
using pll = pair<ll,ll>;

struct SegmentTree {

  inline int left(int p) { return p * 2; }

  inline int right(int p) { return p * 2 + 1; }

  SegmentTree(vector<ll> &vec) {
    n = vec.size();
    int sz = 4 * n;

    tree.assign(sz, {1e18, 1e18});

    build(1, 0, n - 1, vec);
  }

  inline pll merge(const pll& a, const pll& b) { 
    return {
      a.first + b.first,
      min(a.second, b.second + a.first)
    };
  }

  void build(int p, int l, int r, vector<ll> &vec) {
    if (l == r) {
      tree[p] = {vec[l], vec[l]};
      return;
    }

    int m = (l + r) / 2;
    build(left(p), l, m, vec);
    build(right(p), m + 1, r, vec);

    tree[p] = merge(tree[left(p)], tree[right(p)]);
  }

  pll query(int i, int j) { return query(1, 0, n - 1, i, j); }

  void update(int i, ll v) { update(1, 0, n - 1, i, v); }

  vector<pair<ll, ll>> tree;
  int n;

private:
  pll query(int p, int l, int r, int i, int j) {
    if (i > j) // valor impossível. merge() deve ignorá-lo
      return {0, 1e18};
    if (l >= i && r <= j)
      return tree[p];

    int m = (l + r) / 2;
    return merge(query(left(p), l, m, i, min(m, j)),
                 query(right(p), m + 1, r, max(i, m + 1), j));
  }

  void update(int p, int l, int r, int i, ll v) {
    if (l == r) {
      tree[p] = {v, v};
      return;
    }

    int m = (l + r) / 2;
    if (i <= m)
      update(left(p), l, m, i, v);
    else
      update(right(p), m + 1, r, i, v);
    tree[p] = merge(tree[left(p)], tree[right(p)]);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;

  vector<ll> gain_b(n), loss_c(n);
  for (auto& g : gain_b)
    cin >> g;
  for (auto& l : loss_c)
    cin >> l;

  vector<ll> diff(2*n);
  for (int i = 0; i < 2*n; ++i)
    diff[i] = gain_b[i%n] - loss_c[i%n];

  SegmentTree st(diff);
  while (q--) {
    int op, i;
    cin >> op >> i;

    if (op == 1) {
      if (diff[i-1] < 0) {
        cout << i << '\n';
        continue;
      }

      auto[pref_sum, min_value] = st.query(i-1, 2*n - 1);
      if (min_value >= 0) {
        cout << "-1\n";
        continue;
      }

      int l = i-1, r = 2*n - 1;
      while (l <= r) {
        int mid = (l+r)/2;
        if (st.query(i-1, mid).second < 0)
          r = mid - 1;
        else
          l = mid + 1;
      }

      l++;
      if (l <= n)
        cout << l << '\n';
      else
        cout << l - n << '\n';
    } else if (op == 2) {
      int x;
      cin >> x;

      gain_b[i-1] = x;
      ll old_diff = exchange(diff[i-1], gain_b[i-1] - loss_c[i-1]);

      st.update(i-1, diff[i-1]);
      st.update(i-1 + n, diff[i-1]);
    } else {
      int x;
      cin >> x;

      loss_c[i-1] = x;
      ll old_diff = exchange(diff[i-1], gain_b[i-1] - loss_c[i-1]);
      st.update(i-1, diff[i-1]);
      st.update(i-1 + n, diff[i-1]);
    }
  }
}

