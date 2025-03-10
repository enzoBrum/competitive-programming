#include <bits/stdc++.h>
#include <sstream>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

void kosaraju(int u, vector<vector<int>>& adj, vector<char>& visited, vector<int>& order) {
  visited[u] = true;
  for (auto& v : adj[u])
    if (!visited[v])
      kosaraju(v, adj, visited, order);
  order.push_back(u);
}

int dfs(int u, vector<vector<int>>& adj, vector<char>& visited) {
  visited[u] = true;
  int ans = 0;
  for (auto& v : adj[u])
    if (!visited[v])
      ans += dfs(v, adj, visited);
  return ans + 1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;
  unordered_map<string, int> languages;
  
  vector<unordered_set<int>> speak(n), understand(n);
  cin.ignore(1024, '\n');
  for (int i = 0; i < n; ++i) {
    string line;
    stringstream ss;
    getline(cin, line);
    ss << line;
    
    string lang;
    ss >> lang;
    
    bool can_speak = true;
    while (ss >> lang) {
      if (!languages.contains(lang))
        languages[lang] = languages.size();
      int l = languages[lang];
      
      if (can_speak)
        speak[i].insert(l), can_speak = false;
      understand[i].insert(l);
    }
  }
  
  vector<vector<int>> adj(n), tadj(n);
  for (int u = 0; u < n; ++u) {
    for (int v = 0; v < n; ++v) {
      if (u == v)
        continue;
      for (auto& lang : speak[u])
        if (understand[v].contains(lang))
          adj[u].push_back(v), tadj[v].push_back(u);
    }
  }
  
  vector<int> order;
  vector<char> visited(n, 0);
  
  for (int u = 0; u < n; ++u)
    if (!visited[u])
      kosaraju(u, adj, visited, order);
  
  fill(all(visited), false);
  
  int gt_scc = 0;
  for (auto it = order.rbegin(); it != order.rend(); ++it)
    if (!visited[*it])
      gt_scc = max(gt_scc, dfs(*it, tadj, visited));
  cout << n - gt_scc << '\n';
}
