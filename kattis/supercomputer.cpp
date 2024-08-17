#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

struct FenwickTree {
  vector<int> ft;
  FenwickTree(int n) : ft(n + 1) {}

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

  int n, k;
  cin >> n >> k;
  FenwickTree ft(n);

  while (k--) {
    char op;
    cin >> op;

    if (op == 'F') {
      int i;
      cin >> i;

      int curr_val = ft.query(i, i);
      ft.update(i, curr_val ? -1 : 1);
    } else {
      int l, r;
      cin >> l >> r;
      cout << ft.query(l, r) << '\n';
    }
  }
}
