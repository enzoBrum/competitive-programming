#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

bool kahn(vector<vector<int>>& adj, vector<int> degree, int ignored, int goal) {
  queue<int> q;
  q.push(0);
  
  int steps = -1;
  while (!q.empty() && steps < goal) {
    auto u = q.front();
    q.pop();

    steps++;

    for (auto& v : adj[u]) {
      if (v == ignored)
        continue;
      degree[v]--;
      if (!degree[v])
        q.push(v);
    }
  }
  
  return steps == goal;
}

int total_required(vector<vector<int>>& adj, vector<int>& degree, int goal) {
  int ret = 0;
  for (int u = 1; u < adj.size(); ++u)
    if (!kahn(adj, degree, u, goal))
      ret++;
  return ret;
}

int total_never_visited(vector<vector<int>>& tadj, int goal) {
  int ret = 0;
  for (int u = 1; u < tadj.size(); ++u) {
    queue<int> q;
    vector<bool> visited(tadj.size(), 0);
    visited[u] = 1;
    q.push(u);

    int steps = -1;
    bool reach_zero = false;
    while (!q.empty()) {
      auto u = q.front();
      q.pop();

      steps++;
      visited[u] = true;
      if (u == 0) {
        reach_zero = true;
        continue;
      }
      for (auto& v : tadj[u])
        if (!visited[v])
          q.push(v), visited[v] = true;
    }
    
    if (!reach_zero || steps > goal)
      ret++;
  }
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int a, b, n, m;
  cin >> a >> b >> n >> m;

  n++;
  vector<vector<int>> adj(n), tadj(n);
  vector<int> in_degree(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    u++, v++;
    adj[u].push_back(v);
    in_degree[v]++;
    tadj[v].push_back(u);
  }
  
  for (int u = 1; u < n; ++u)
    if (!in_degree[u])
      adj[0].push_back(u), tadj[u].push_back(0), in_degree[u] = 1;
  
  int num_a = total_required(adj, in_degree, a);
  int num_b = total_required(adj, in_degree, b);
  int num_never = total_never_visited(tadj, b);

  cout << num_a << '\n' << num_b << '\n' << num_never << '\n';
}
