#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

vector<vector<int>> adj;
vector<char> visited;
vector<int> degree, og_degree;

void dfs(int u) {
  visited[u] = true;

  for (auto& v  : adj[u]) {
    if (visited[v])
      continue;

    degree[v]--;
    if (degree[v] <= og_degree[v]/2)
      dfs(v);
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int c, p, x, l;
  cin >> c >> p >> x >> l;

  adj.assign(c, {});
  visited.assign(c, false);
  degree.assign(c, 0);
  og_degree.assign(c, 0);
  
  while (p--) {
    int u, v;
    cin >> u >> v;
    u--, v--;

    adj[u].push_back(v);
    adj[v].push_back(u);
    og_degree[u]++;
    og_degree[v]++;
  }
  
  degree = og_degree;
  l--, x--;
  
  degree[l] = 0;
  dfs(l);
  
  //for (auto& d : og_degree)
  //  cout << d << ' ';
  //cout << endl;
  //for (auto& d : degree)
  //  cout << d << ' ';
  //cout << endl;

  cout << (degree[x] <= og_degree[x]/2 ? "leave\n" : "stay\n");
}
