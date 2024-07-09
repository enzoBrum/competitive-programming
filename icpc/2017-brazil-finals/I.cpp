#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using piii = pair<int, pii>;
using ll = long long;
using ull = unsigned long long;

void binary_lift(int u, int p, int w, int d, vector<vector<pii>> &tr,
                 vector<vector<int>> &up, vector<vector<int>> &upw,
                 vector<int> &depth, vector<int> &tin, vector<int> &tout,
                 int &timer, int l) {
  tin[u] = ++timer;
  up[u][0] = p;
  upw[u][0] = w;
  depth[u] = d;
  for (int i = 1; i <= l; ++i) {
    up[u][i] = up[up[u][i - 1]][i - 1];
    upw[u][i] = max(upw[u][i - 1], upw[up[u][i - 1]][i - 1]);
  }

  for (auto &[w, v] : tr[u])
    if (v != p)
      binary_lift(v, u, w, d + 1, tr, up, upw, depth, tin, tout, timer, l);
  tout[u] = ++timer;
}

bool is_ancestor(int u, int v, vector<int> &tin, vector<int> &tout) {
  return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int get_w_from_lca(int u, int lca, vector<vector<int>> &up,
                   vector<vector<int>> &upw, int du, int dlca) {
  int ans = 0;


  for (int i = 31; i >= 0; --i) {
    if ((du - dlca)&(1 << i)) {
      ans = max(ans, upw[u][i]);
      u = up[u][i];
    }
  }

  
  return ans;
}

int lca_w(int l, int u, int v, vector<int> &tin, vector<int> &tout,
          vector<vector<int>> &up, vector<vector<int>> &upw,
          vector<int> &depth) {
  if (is_ancestor(u, v, tin, tout))
    return get_w_from_lca(v, u, up, upw, depth[v], depth[u]);
  if (is_ancestor(v, u, tin, tout))
    return get_w_from_lca(u, v, up, upw, depth[u], depth[v]);

  int ans = 0;
  int lca = u;
  for (int i = l; i >= 0; --i)
    if (!is_ancestor(up[lca][i], v, tin, tout))
      lca = up[lca][i];

  lca = up[lca][0];
  return max(get_w_from_lca(u, lca, up, upw, depth[u], depth[lca]),
             get_w_from_lca(v, lca, up, upw, depth[v], depth[lca]));
}

tuple<int, vector<vector<pii>>, set<pii>> prim(vector<vector<pii>> &adj) {
  priority_queue<piii, vector<piii>, greater<piii>> pq;

  vector<vector<pii>> tr(adj.size());
  vector<bool> visited(adj.size(), 0);
  set<pii> edges;

  int n = adj.size();
  int num_visited = 0;
  int cost = 0;
  visited[0] = true;

  for (auto &[w, v] : adj[0]) {
    pq.push({w, {v, 0}});
  }

  while (!pq.empty() && num_visited != n - 1) {
    auto [w, pr] = pq.top();
    pq.pop();

    auto &[u, p] = pr;

    if (visited[u])
      continue;

    num_visited++;
    visited[u] = true;
    cost += w;
    edges.insert({p, u});

    tr[p].push_back({w, u});
    for (auto &[wv, v] : adj[u])
      if (!visited[v])
        pq.push({wv, {v, u}});
  }

  return {cost, tr, edges};
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int n, r;
  cin >> n >> r;

  vector<vector<pii>> adj(n);
  vector<unordered_map<int, int>> pmatrix(n); // pseudo-matrix
  while (r--) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});

    pmatrix[u][v] = w;
    pmatrix[v][u] = w;
  }

  auto [cost, tr, edges] = prim(adj);

  int l = ceil(log2(n));
  vector<int> tin(n), tout(n), depth(n);
  int timer = 0;
  vector<vector<int>> up(n, vector<int>(l + 1)), upw(n, vector<int>(l + 1));

  binary_lift(0, 0, 0, 1, tr, up, upw, depth, tin, tout, timer, l);

  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;

    if (edges.find({u, v}) != edges.end() ||
        edges.find({v, u}) != edges.end()) {
      cout << cost << '\n';
      continue;
    }

    cout << cost + pmatrix[u][v] - lca_w(l, u, v, tin, tout, up, upw, depth)
         << '\n';
  }
}
