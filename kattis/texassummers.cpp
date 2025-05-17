#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int INF = 1e9;

pair<vector<int>, vector<int>> dijkstra(int s, int t, vector<vector<pii>>& adj) {
  vector<int> dist(adj.size(), 1e9);
  vector<int> p(adj.size(), -1);
  
  dist[s] = 0;
  p[s] = -1;
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  
  pq.push({0, s});
  while (!pq.empty()) {
    auto[du, u] = pq.top(); pq.pop();
    
    if (du > dist[u])
      continue;
    
    if (u == t)
      break;
    
    for (auto&[w, v] : adj[u]) {
      if (du + w < dist[v]) {
        dist[v] = du + w;
        pq.push({dist[v], v});
        p[v] = u;
      }
    }
  }
  
  return {dist, p};
}

signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  
  vector<vector<pii>> adj(n+2);
  vector<pii> points(n+2);
  
  for (int i = 0; i < n+2; ++i)
    cin >> points[i].first >> points[i].second;
  for (int i = 0; i < n+2; ++i) {
    for (int j = i+1; j < n+2; ++j) {
      auto[ix, iy] = points[i];
      auto[jx, jy] = points[j];
      
      int d = abs(ix-jx)*abs(ix-jx) + abs(iy-jy)*abs(iy-jy);
      
      adj[i].push_back({d, j});
      adj[j].push_back({d, i});
      //cout << "(" << i << ", " << j << ") -> " << d*d << endl;
    }
  }
  
  auto[d, p] = dijkstra(n, n+1, adj);
  
  vector<int> ans;
  int cur = p[n+1];
  
  while (cur != n) {
    ans.push_back(cur);
    cur = p[cur];
  }
  
  if (ans.size() == 0)
    cout << "-\n";
  else 
    for (auto it = ans.rbegin(); it != ans.rend(); ++it)
      cout << *it << '\n';
}