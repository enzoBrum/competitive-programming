#include <bits/stdc++.h>
#include <sstream>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

unordered_map<string, int> sint;
vector<string> ints;
void dfs(int u, vector<bool>& visited, vector<int>& ts, vector<vector<int>>& adj) {
  visited[u] = true;
  for (auto& v : adj[u])
    if (!visited[v])
      dfs(v, visited, ts, adj);
  ts.push_back(u);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  cin.ignore(1024, '\n');
  vector<vector<int>> adj(n);
  
  while (n--) {
    string line;
    getline(cin, line);
    
    stringstream ss;
    ss << line;

    string rule;
    ss >> rule;
    
    rule.pop_back();

    if (!sint.contains(rule)) {
      int num = sint.size();
      ints.push_back(rule);
      sint[rule] = num;
    }
    
    int u = sint[rule];

    string fv;
    while (ss >> fv) {
      if (!sint.contains(fv)) {
        int num = sint.size();
        ints.push_back(fv);
        sint[fv] = num;
      }
      
      int v = sint[fv];
      adj[v].push_back(u);
    }
  }
  
  string changed;
  cin >> changed;
  
  vector<int> ts;
  vector<bool> visited(sint.size(), false);
  dfs(sint[changed], visited, ts, adj);
  
  for (auto it = ts.rbegin(); it != ts.rend(); ++it)
    cout << ints[*it] << '\n';
  
}
