#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

/**
1. dfs para achar número de promoções mínimo para chegar a cada empregado. Número de promoções de um empregado X = número de promoções dos empregados acima de X + 1
2. Empregados com número de promoçoes=A -> cria grafo não direcionado partindo delas até o sentinela e conta pontos de articulação
3. Conta empregados cujo número de prmoções é maior que B
*/

vector<int> find_num_of_promotions(vector<vector<int>>& adj, vector<int>& degree) {
  vector<int> num_of_promotions(adj.size());
  queue<int> q;
  q.push(0);
  
  num_of_promotions[0] = -1;
  
  while (!q.empty()) {
    auto u = q.front(); q.pop();
    
    num_of_promotions[u]++;
    for (auto& v : adj[u]) {
      degree[v]--;
      num_of_promotions[v] += num_of_promotions[u];
      if (degree[v] == 0)
        q.push(v);
    }
  }
  return num_of_promotions;
}

int UNVISITED = 0, EXPLORED = 1, VISITED = 2;
void tarjan(int u, int p, vector<bool>& visited, vector<bool>& cutpoint, vector<vector<int>>& adj, vector<int>& tin, vector<int>& low, int& cnt, vector<int>& promotions, int goal) {
  tin[u] = low[u] = cnt++;
  visited[u] = true;
  for (auto& v : adj[u]) {
    if (v == p || promotions[v] > goal)
      continue;
    
    if (visited[v])
      low[u] = min(low[u], tin[v]);
    else {
      tarjan(v, u, visited, cutpoint, adj, tin, low, cnt, promotions, goal);
      
      if (low[v] >= tin[u])
        cutpoint[u] = true;
      low[u] = min(low[u], low[v]);
    }
  }
}

int get_num_of_required_promotions(vector<vector<int>> undirected_adj, vector<int>& promotions, int goal) {
  undirected_adj.push_back({});
  int sentinel = undirected_adj.size() - 1;
  
  for (int u = 0; u < sentinel; ++u)
    if (promotions[u] == goal)
      undirected_adj[u].push_back(sentinel), undirected_adj[sentinel].push_back(u);
  
  vector<bool> visited(undirected_adj.size(), 0), cutpoint(undirected_adj.size(), 0);
  vector<int> tin(undirected_adj.size()), low(undirected_adj.size());
  int cnt = 0;

  tarjan(sentinel, -1, visited, cutpoint,undirected_adj, tin, low, cnt, promotions, goal);
  
  int ret = 0;
  for (int u = 0; u < sentinel; ++u)
    if (cutpoint[u])
      ret++;
  return ret;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int a, b, n, m;
  cin >> a >> b >> n >> m;

  n++;
  vector<vector<int>> adj(n), undirected_adj(n);
  vector<int> in_degree(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    u++, v++;
    adj[u].push_back(v);
    in_degree[v]++;
    undirected_adj[u].push_back(v);
    undirected_adj[v].push_back(u);
  }
  
  for (int u = 1; u < n; ++u)
    if (!in_degree[u])
      adj[0].push_back(u), undirected_adj[0].push_back(u), undirected_adj[u].push_back(0), in_degree[u] = 1;
  
  auto promotions = find_num_of_promotions(adj, in_degree);
  
  
  int num_a = get_num_of_required_promotions(undirected_adj, promotions, a);
  int num_b = get_num_of_required_promotions(undirected_adj, promotions, b);

  
  queue<int> q;
  vector<bool> visited(n, false);
  for (int u = 0; u < n; ++u)
    if (!in_degree[u])
      q.push(u);
  
  int num_best = count_if(all(promotions), [&b](int v) { return v > b; });
  
  cout << num_a << '\n' << num_b << '\n' << n - num_best << '\n';
}
