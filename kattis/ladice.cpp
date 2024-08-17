#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

struct UnionFind {
  UnionFind(int n) {
    p.resize(n);
    rank.assign(n, 1);
    set_size.assign(n, 1);
    free_drawers.assign(n, 1);
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

    set_size[j] += set_size[i];
    free_drawers[j] += free_drawers[i];
  }

  vector<int> p, rank, set_size, free_drawers;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, l;
  cin >> n >> l;

  UnionFind uf(l);
  while (n--) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    uf.union_set(a, b);

    int p = uf.find_set(a);
    if (uf.free_drawers[p]) {
      uf.free_drawers[p]--;
      cout << "LADICA\n";
    } else {
      cout << "SMECE\n";
    }
  }
}
