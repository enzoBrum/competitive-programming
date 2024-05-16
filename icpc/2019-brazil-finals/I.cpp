#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> visited;
vector<int> sorted;

void dfs(int v) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u])
            dfs(u);
    }
    sorted.push_back(v);
}

void topological_sort() {
    visited.assign(n, false);
    sorted.clear();
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    reverse(sorted.begin(), sorted.end());
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  int l;
  cin >> n >> l;

  adj.resize(n);
  visited.assign(n, false);
  vector<bool> user_visited(n, false);

  for (int i = 0; i < l; ++i) {
    int k;
    cin >> k;
    while (k--) {
      int v;
      cin >> v;
      v--;
      adj[i].push_back(v);
    }
  }

  topological_sort();
  
  vector<int> d(n,0);
  d[0] = 1;
  
  for (auto& u : sorted) {
    for (auto& v : adj[u]) {
      d[v] += d[u];
      d[v] %= ((int) 1e9 + 7);
    }
  }
  
  int ans = 0;
  for (int i = l; i < n; ++i) {
    ans += d[i];
    ans %= ((int) 1e9 + 7);
  }
  cout << ans << ' ';

  
  vector<bool> visited2(n, false);
  queue<int> q;
  q.push(0);
  ans = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    
    for (auto& v : adj[u]) {
      if (visited2[v]) continue;
      visited2[v] = true;
      if (v >= l) ans++;
      q.push(v);
    }
  }

  cout << ans << ' ';
}

