#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<long long, int>;
using ll = long long;
using ull = unsigned long long;

using iii = tuple<int, int, int>;

int num_edges;
ll prim(vector<vector<pii>> &adj, vector<int>& starting_stations) {
  vector<bool> visited(adj.size(), 0);
  priority_queue<pii, vector<pii>, greater<pii>> pq;

  for (auto& s : starting_stations) {
    visited[s-1] = true;    
    for (auto&[w, v] : adj[s-1])
      pq.push({w, v});
  }
  
  ll ans = 0;
  int num_taken = starting_stations.size();
  num_edges = 0;
  while (!pq.empty()) {
    auto[w, u] = pq.top();
    pq.pop();
    
    if (visited[u])
      continue;
    num_edges++;
    visited[u] = true;
    ans += w;
    num_taken++;
    for (auto&[wv, v] : adj[u])
      if (!visited[v])
        pq.push({wv, v});
    if (num_taken == adj.size())
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
    int n, m, l, s;
    cin >> n >> m >> l >> s;
    vector<vector<pii>> adj(n);
    
    vector<int> starting_stations(s);
    for (auto& s : starting_stations)
      cin >> s;
    
    while (m--) {
      int u, v, w;
      cin >> u >> v >> w;
      u--, v--;

      adj[u].push_back({w, v});
      adj[v].push_back({w, u});
    }

    cout << prim(adj, starting_stations) + l * num_edges << '\n';
  }
}
