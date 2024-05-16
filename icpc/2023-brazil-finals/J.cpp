#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <bit>
#include <unordered_map>

using namespace std;
using pii = pair<int, int>;


/**
- Cada centróide tem um set com as cidades e a quantidade de dinheiro nelas
- Cada centróide tem uma sparse table que permite descobrir a cidade com a menor distância no intervalo [L, R], onde L é a quantidade de dinheiro maior que a atual
- A cada query, são feitas log (n) chamadas aos centróides...

*/


struct SparseTable {
  vector<vector<pii>> st;
  int k = 25;
  int n;

  pii min_pii(pii& a, pii& b) {
    if (a.second == b.second)
      return (a.first < b.first) ? a : b;
    return a.second < b.second ? a : b;
  }

  SparseTable() {};
  
  SparseTable(const vector<pii>& vec) {
    n = vec.size();
    st.assign(k+1, vector<pii>(n));
    st[0] = vec;
     
    for (int i = 1; i <= k; ++i)
      for (int j = 0; j + (1 << i) <= n; ++j)
        st[i][j] = this->min_pii(st[i-1][j], st[i-1][j + (1 << (i-1))]);
  }

  pii query(int l, int r) {
    int i = bit_width((unsigned long) (r - l + 1)) - 1;
    return this->min_pii(st[i][l], st[i][r - (1 << i) + 1]);
  }
};

struct CentroidDecomposition {
  vector<vector<int>> tree;
  vector<int> subtrees_sz;
  vector<vector<pii>> parents;
  vector<bool> removed;
  vector<SparseTable> st;
  vector<vector<pii>> children;

  CentroidDecomposition(vector<vector<int>> adj)
    :tree{std::move(adj)} {
    int n = tree.size();

    subtrees_sz.resize(n);
    removed.assign(n, false);
    parents.resize(n);
    children.resize(n);
    // st.resize(n);

    centroid_decomposition(0, -1);
  }

  void calculate_subtree_sizes(int u, int p = -1) {
    subtrees_sz[u] = 1;
    for (auto v : tree[u]) {
      if (v == p || removed[v])
        continue;
      calculate_subtree_sizes(v, u);
      subtrees_sz[u] += subtrees_sz[v];
    }
  }

  int find_centroid(int u, int p, int n) {
    for (auto v : tree[u]) {
      if (v == p || removed[v])
        continue;
      if (subtrees_sz[v] > n / 2)
        return find_centroid(v, u, n);
    }

    return u;
  }

  

  void calculate_distance_to_centroid(int u, int p, int centroid, int d) {
    for (auto v : tree[u]) {
      if (v == p || removed[v])
        continue;
      
      calculate_distance_to_centroid(v, u, centroid, d + 1);
    }
    children[centroid].push_back({u, d});
    parents[u].push_back({centroid, d});
  }

  void centroid_decomposition(int u, int p = -1) {
    calculate_subtree_sizes(u);
    int centroid = find_centroid(u, p, subtrees_sz[u]);

    for (auto v : tree[centroid]) {
      if (removed[v])
        continue;
      calculate_distance_to_centroid(v, centroid, centroid, 1);
    }

    sort(children[centroid].begin(), children[centroid].end());

    if (children[centroid].size()) {
      pii best = children[centroid].back();
      for (auto it = children[centroid].rbegin(); it != children[centroid].rend(); ++it) {
        if (it->second <= best.second)
          best = *it;
        else
          *it = best;
      }
    }  


    // st[centroid] = SparseTable(children[centroid]);
    removed[centroid] = true;

    for (auto v : tree[centroid]) {
      if (removed[v])
        continue;
      centroid_decomposition(v, u);
    }
  }

  pii get_closest_city(int p, pii& fake_pair) {
    vector<pii>& vec = children[p];
    auto it = upper_bound(vec.begin(), vec.end(), fake_pair, [](const pii& a, const pii& b) { return a.first < b.first; });

    if (it == vec.end())
      return {1e9, 1e9};

    return *it;
    // int idx = it - vec.begin();
    // return st[p].query(idx, vec.size() - 1);
  }

  int query(int u) {
    pii fake_pair = {u, 0};
    auto[ans, curr_dist] = get_closest_city(u, fake_pair);
    
    for (auto&[p, pdist] : parents[u]) {
      if (pdist > curr_dist) continue;
      if (p > u && (p < ans || pdist < curr_dist)) {
        ans = p;
        curr_dist = pdist;
        continue;
      } 


      auto[city, dist] = get_closest_city(p, fake_pair);
      if (dist + pdist < curr_dist || (dist + pdist == curr_dist && city < ans && city > u)) {
        curr_dist = pdist + dist;
        ans = city;
      }
    }
    
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n;
  cin >> n;

  vector<vector<int>> adj(n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    a--, b--;

    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  CentroidDecomposition cd(std::move(adj));

  for (int i = 0; i < n; ++i) {
    int ans = cd.query(i);
    if (ans == 1e9)
      cout << i+1 << ' ';
    else
      cout << ans+1 << ' ';
  }
}

