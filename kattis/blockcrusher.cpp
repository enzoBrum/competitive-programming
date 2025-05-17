#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<pii> directions = {
  {1, 0},
  {-1, 0},
  {0, 1},
  {0, -1},
  {1, 1},
  {1, -1},
  {-1, 1},
  {-1, -1}
};

pair<vector<int>, vector<int>> dijkstra(int s, vector<vector<pii>>& adj) {
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
    
    for (auto&[w, v] : adj[u]) {
      if (du + w < dist[v]) {
        dist[v] = du + w;
        pq.push({dist[v], v});
        p[v] = u;
      }
    }
  }
  return {p, dist};
}
  

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  
  int h, w;
  while (cin >> h >> w && (h || w)) {
    vector<vector<char>> matrix(h, vector<char>(w));
    for (auto& row : matrix)
      for (auto& cell : row)
        cin >> cell;
    
    vector<vector<pii>> adj(h * w + 2);
    for (int j = 0; j < w; ++j)
      adj[0].push_back({matrix[0][j] - '0', j+1}), adj[(h-1)*w + j + 1].push_back({0, h*w + 1});
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        for (auto&[di, dj] : directions) {
          int fi = i + di, fj = j + dj;
          if (fi < 0 || fi >= h || fj < 0 || fj >= w)
            continue;
          adj[i*w + j + 1].push_back({matrix[fi][fj] - '0', {fi*w + fj + 1}});
        }
      }
    }
    
    auto[p, d] = dijkstra(0, adj);
    
    vector<bool> is_fracture(adj.size(), false);
    
    int cur = p[h*w + 1];
    while (cur != 0) {
      is_fracture[cur] = true;
      cur = p[cur];
    }
    
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j)
        if (is_fracture[i*w + j + 1])
          cout << ' ';
        else
          cout << matrix[i][j];
      cout << '\n';
    }
    cout << '\n';
  }
}
