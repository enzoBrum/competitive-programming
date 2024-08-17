#include <bits/stdc++.h>
#include <sstream>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

struct FenwickTree {
  FenwickTree(int n) { ft.assign(n + 1, 0); }

  FenwickTree(vector<int> &vec) {
    ft.assign(vec.size() + 1, 0);
    for (int i = 0; i < vec.size(); ++i)
      update(i + 1, vec[i]);
  }

  inline int ls_one(int x) { return x & (-x); }

  int query(int r) {
    int sum = 0;
    while (r) {
      sum += ft[r];
      r -= ls_one(r);
    }
    return sum;
  }

  int query(int l, int r) { return query(r) - query(l - 1); }

  void update(int i, int v) {
    while (i < ft.size()) {
      ft[i] += v;
      i += ls_one(i);
    }
  }

  // Finds smallest index i on FenwickTree such that query(1, i) >= rank.
  // I.e: smallest i for [1, i] >= k
  int select(long long k) { // O(log^2 m)
    int lo = 1, hi = ft.size() - 1;
    for (int i = 0; i < 30; ++i) { //  2^30 > 10^9; usually ok
      int mid = (lo + hi) / 2;
      (query(1, mid) < k) ? lo = mid : hi = mid;
    }
    return hi;
  }

  vector<int> ft;
};

// Range Update - Point query
struct RUPQ {
  FenwickTree ft;
  RUPQ(int m) : ft{m} {}

  void range_update(int ui, int uj, int v) {
    ft.update(ui, v);
    ft.update(uj + 1, -v);
  }

  int point_query(int i) { return ft.query(i); }
};

// Range Update - Range Query
struct RURQ {
  RUPQ rupq;
  FenwickTree ft;

  RURQ(int m) : ft{m}, rupq(m) {}

  void range_update(int ui, int uj, int v) {
    rupq.range_update(ui, uj, v);
    ft.update(ui, v * (ui - 1));
    ft.update(uj + 1, -v * uj);
  }

  int query(int j) { return rupq.point_query(j) * j - ft.query(j); }

  int query(int i, int j) { return query(j) - query(i - 1); }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, q;

  cin >> n >> q;

  vector<FenwickTree> fts(6, FenwickTree(n));
  vector<int> ft_values(6);

  for (auto &v : ft_values)
    cin >> v;

  vector<int> types(n);
  for (int i = 0; i < n; ++i) {
    char c;
    cin >> c;

    int idx = c - '0' - 1;
    fts[idx].update(i + 1, 1);
    types[i] = idx;
  }

  while (q--) {
    int op;
    cin >> op;

    if (op == 1) {
      int k, p;
      cin >> k >> p;

      fts[types[k - 1]].update(k, -1);
      fts[p - 1].update(k, 1);
      types[k - 1] = p - 1;
    } else if (op == 2) {
      int p, v;
      cin >> p >> v;
      ft_values[p - 1] = v;
    } else {
      int l, r;
      cin >> l >> r;

      ll ans = 0;
      for (int i = 0; i < 6; ++i)
        ans += ((ll)fts[i].query(l, r) * (ll)ft_values[i]);
      cout << ans << '\n';
    }
  }
}
