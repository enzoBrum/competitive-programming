#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

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

using iii = tuple<int, int, int>;

int kruskal(vector<iii>& edges, int n) {
  UnionFind uf(n);

  int ans = 0;
  int taken = 0;
  for (auto&[w, u, v] : edges) {
    if (uf.same_set(u, v))
      continue;
    
    uf.union_set(u, v);
    taken++;
    ans += w;
    
    if (taken == n - 1)
      break;
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;

  while (t--) {
    int m, c;
    cin >> m >> c;

    vector<iii> edges((c * (c-1))/2);
    for (auto&[w, u, v] : edges)
      cin >> u >> v >> w;
    
    sort(all(edges));
    int mst_len = kruskal(edges, c);
    cout << (mst_len + c <= m ? "yes\n" : "no\n");
  }
}
