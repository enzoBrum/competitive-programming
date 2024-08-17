#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

static vector<int> ft;

struct FenwickTree {
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
    for (int i = 0; i < 30; ++i) {
      int mid = (lo + hi) / 2;
      (query(1, mid) < k) ? lo = mid : hi = mid;
    }
    return hi;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  ft.resize(2e5 + 10, 0);

  int t;
  cin >> t;

  while (t--) {
    int m, r;
    cin >> m >> r;
    FenwickTree fenwick;
    vector<int> pos(m + 1);
    int offset = 1e5;
    for (int i = 1; i <= m; ++i)
      pos[i] = offset + i;
    fill(ft.begin(), ft.end(), 0);

    for (int i = offset + 2; i <= offset + m; ++i)
      fenwick.update(i, 1);

    while (r--) {
      int a;
      cin >> a;

      int ans = fenwick.query(pos[a]);
      fenwick.update(pos[a], -1);

      pos[a] = offset--;
      fenwick.update(pos[a] + 1, 1);

      cout << ans << ' ';
    }
    cout << '\n';
  }
}
