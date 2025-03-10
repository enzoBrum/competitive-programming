#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int solve(vector<vector<int>>& adj, vector<int>& stages, vector<int> degree, int begin) {
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  
  auto og_degree = degree;
  for (int i = 0; i < adj.size(); ++i)
    if (degree[i] == 0)
      pq.push({stages[i] == begin ? 0 : 1, i});
  
  if (pq.empty())
    return 1e9;
  
  int ans = 0;
  int cur_stage = begin;
  while (!pq.empty()) {
    auto[_, u] = pq.top(); pq.pop();
    
    if (cur_stage != stages[u])
      cur_stage = stages[u], ans++;
    
    for (auto& v : adj[u]) {
      degree[v]--;
      
      if (degree[v] <= 0)
        pq.push({stages[v] == cur_stage ? ans  : ans + 1, v});
    }
  }
  
  return ans;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> stages(n);
    for (auto& s : stages)
      cin >> s;

    vector<vector<int>> adj(n);
    vector<int> degree(n, 0);
    while (m--) {
      int u, v;
      cin >> u >> v;
      u--, v--;

      adj[u].push_back(v);
      degree[v]++;
    }
    
    cout << min(solve(adj, stages, degree, 1), solve(adj, stages, degree, 2)) << '\n';
    
  }
}
