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
  
  int n, m;
  cin >> m >> n;

  unordered_map<string, int> mp;
  mp["English"] = 0;
  for (int i = 1; i <= m; ++i) {
    string s;
    cin >> s;
    mp[s] = i;
  }
  
  vector<vector<pii>> adj(m+1);
  while (n--) {
    string s1, s2;
    int w;
    cin >> s1 >> s2 >> w;
    
    int u = mp[s1], v = mp[s2];
    adj[u].push_back({w, v});
    adj[v].push_back({w, u});
  }
  
  queue<int> q;
  int INF = 1e9;
  vector<int> cost(m+1, INF);
  vector<int> d(m+1, INF);
  d[0] = cost[0] = 0;
  q.push(0);
  
  vector<char> visited(m+1, false);
  visited[0] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto&[w, v] : adj[u]) { 
      if (d[v] == INF) {
        d[v] = d[u] + 1;
        cost[v] = w;
      } else if (d[v] == d[u] + 1 && w < cost[v]) {
        cost[v] = w;
      }
      
      if (!visited[v])
        q.push(v), visited[v] = true;
    }
  }
  
  for (int i = 1; i < m+1; ++i)
    if (!visited[i]) {
      cout << "Impossible\n";
      return 0;
    }

  cout << (accumulate(all(cost), 0) - cost[0]) << '\n';
}
