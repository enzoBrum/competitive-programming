#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

// 0-based index
struct UnionFind {
  UnionFind(int n) {
    p.resize(n);
    rank.assign(n, 1);
    set_size.assign(n, 1);
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
  }

  vector<int> p, rank, set_size;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  UnionFind uf(500001);

  int ans = 0;
  while (n--) {
    int m;
    cin >> m;

    unordered_map<int, int> mp;
    vector<int> vec(m);
    for (auto &v : vec) {
      cin >> v;
      mp[uf.find_set(v)]++;
    }

    bool valid = true;
    for (auto &[k, v] : mp) {
      if (uf.set_size[k] != v) {
        valid = false;
        break;
      }
    }

    if (!valid)
      continue;

    ans++;

    for (int i = 1; i < m; ++i)
      uf.union_set(vec[i], vec[i - 1]);
  }

  cout << ans << '\n';
}
