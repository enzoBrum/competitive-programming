#include <bits/stdc++.h>
#include <sstream>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  unordered_map<string, int> mp;
  vector<vector<int>> adj(n*n);
  vector<string> vec;
  
  cin.ignore(1024, '\n');

  while (n--) {
    string line;
    getline(cin, line);

    stringstream ss;
    ss << line;

    string u;
    ss >> u;

    if (!mp.contains(u))
      mp[u] = mp.size(), vec.push_back(u);
    
    string v;
    int ui = mp[u];
    while (ss >> v) {
      if (!mp.contains(v))
        mp[v] = mp.size(), vec.push_back(v);
      int vi = mp[v];
      adj[ui].push_back(vi);
      adj[vi].push_back(ui);
    }
  }
  

  string first, last;
  cin >> first >> last;
  
  if (!mp.contains(first) || !mp.contains(last)) {
    cout << "no route found\n";
    return 0;
  }

  int f = mp[first], l = mp[last];
  
  vector<int> p(adj.size(), -1);
  vector<char> visited(adj.size(), false);
  
  queue<int> q;
  q.push(f);

  visited[f] = true;

  while (!q.empty()) {
    auto u = q.front(); q.pop();

    for (auto& v : adj[u]) {
      if (visited[v])
        continue;
      visited[v] = true;
      q.push(v);
      p[v] = u;
    }
  }
  
  if (!visited[l])
    cout << "no route found\n";
  else {
    vector<string> path;
    int cur = l;
    
    while (cur != -1) {
      path.push_back(vec[cur]);
      cur = p[cur];
    }
    
    for (auto it = path.rbegin(); it != path.rend(); ++it)
      cout << *it << ' ';
    cout << '\n';
  }
}
