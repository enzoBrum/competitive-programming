#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

struct UnionFind {
  UnionFind(int n) {
    p.resize(n);
    sum.resize(n);
    rank.assign(n, 1);
    set_size.assign(n, 1);
    iota(p.begin(), p.end(), 0);
    iota(sum.begin(), sum.end(), 1ll);
  }

  int find_set(int i) {
    if (p[i] == i)
      return i;

    int new_p = find_set(p[i]);
    children[p[i]].erase(i);
    children[new_p].insert(i);
    return p[i] = new_p;
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
    children[j].insert(i);
    if (rank[i] == rank[j])
      rank[j]++;

    set_size[j] += set_size[i];
    sum[j] += sum[i];
  }

  void move(int i, int j) {
    int pi = find_set(i), pj = find_set(j);
    if (pi == pj)
      return;

    if (set_size[pi] == 1)
      return union_set(i, j);

    sum[pi] -= (i + 1);
    set_size[pi]--;
    rank[pi]--;

    sum[pj] += i + 1;
    set_size[pj]++;
    rank[pj]++;

    p[i] = pj;
    children[pj].insert(i);

    if (pi != i)
      children[pi].erase(i);

    if (children[i].size() == 0) {
      sum[i] = i + 1;
      set_size[i] = rank[i] = 1;
      return;
    }

    auto it = children[i].begin();

    int first = *it;
    if (pi == i) {
      p[first] = first;
      sum[first] = sum[pi];
      set_size[first] = set_size[pi];
      rank[first] = rank[pi];
    } else {
      p[first] = pi;
      children[pi].insert(first);
    }
    sum[i] = i + 1;
    set_size[i] = rank[i] = 1;

    it++;
    while (it != children[i].end()) {
      p[*it] = first;
      children[first].insert(*it);
      it++;
    }
    children[i].clear();
  }

  vector<int> p, rank, set_size;
  unordered_map<int, unordered_set<int>> children;
  vector<ll> sum;
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n, m;
  while (cin >> n >> m && n && m) {
    UnionFind uf(n);
    while (m--) {
      int c, p, q;
      cin >> c >> p;

      if (c == 3) {
        p = uf.find_set(p - 1);
        cout << uf.set_size[p] << ' ' << uf.sum[p] << '\n';
        continue;
      }

      cin >> q;

      p--, q--;
      if (c == 1)
        uf.union_set(p, q);
      else if (c == 2)
        uf.move(p, q);
    }
  }
}
