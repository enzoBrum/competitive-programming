#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

struct UnionFind {
  UnionFind(int n) {
    p.resize(n);
    rank.assign(n, 1);
    iota(p.begin(), p.end(), 0);
  }

  int find_set(int i) {
    if (p[i] == i)
      return i;

    return p[i] = find_set(p[i]);
  }

  inline bool same_set(int i, int j) { return find_set(i) == find_set(j); }

  void union_set(int i, int j) {
    if (same_set(i, j))
      return;

    i = p[i];
    j = p[j];

    if (rank[i] > rank[j])
      swap(i, j);

    p[i] = j;
    if (rank[i] == rank[j])
      rank[j]++;
  }

  vector<int> p, rank;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, q;
  cin >> n >> q;

  UnionFind uf(n);
  while (q--) {
    char c;
    int a, b;
    cin >> c >> a >> b;

    if (c == '?')
      cout << (uf.same_set(a, b) ? "yes\n" : "no\n");
    else
      uf.union_set(a, b);
  }
}
