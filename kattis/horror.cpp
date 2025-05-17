#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n, h, l;
  cin >> n >> h >> l;
  vector<vector<int>> adj(n);
  
  vector<char> horror(n, 0);
  int INF = 1e9;
  vector<int> hi(n, INF);
  queue<int> q;
  vector<bool> visited(n, false);
  while (h--) {
    int x;
    cin >> x;
    hi[x] = 0;
    horror[x] = 1;
    
    q.push(x);
    visited[x] = true;
  }
  
  while (l--) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    int h = hi[u];
    for (auto& v : adj[u]) {
      if (hi[v] != 0)
        hi[v] = hi[v] == INF ? h+1 : min(hi[v], h+1);
      if (visited[v])
        continue;
      visited[v] = true;
      q.push(v);
    }
  }
  
  int mx = -1, mx_idx = -1;
  for (int i = 0; i < n; ++i) {
    if (hi[i] > mx)
      mx = hi[i], mx_idx = i;
  }
  
  cout << mx_idx << '\n';
}
