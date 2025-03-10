#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int UNVISITED = 0, EXPLORED = 1, VISITED = 2;

void dfs(int u, vector<vector<int>>& adj, vector<char>& visited, vector<char>& cycle, vector<int>& st) {
  visited[u] = EXPLORED;
  st.push_back(u);
  
  for (auto& v : adj[u]) {
    if (visited[v] == VISITED) {
      if (!cycle[v])
        continue;
      
      int i = st.size() - 1;
      while (i >= 0)
        cycle[st[i--]] = true;
    }
    else if (visited[v] == EXPLORED) {
      cycle[v] = true;
      int i = st.size() - 1;
      while (i >= 0)
        cycle[st[i--]] = true;
    } else {
      dfs(v, adj, visited, cycle, st);
    }
  }

  visited[u] = VISITED;
  st.pop_back();
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  unordered_map<string, int> city_to_i;
  
  vector<vector<int>> adj(n);
  
  for (int i = 0; i < n; ++i) {
    string o, d;
    cin >> o >> d;

    if (!city_to_i.contains(o)) {
      city_to_i[o] = city_to_i.size();
    }
    if (!city_to_i.contains(d)) {
      city_to_i[d] = city_to_i.size();
    }
    
    int oi = city_to_i[o], di = city_to_i[d];
    
    adj[oi].push_back(di);
  }
  
  vector<char> visited(n, 0);
  vector<char> cycle(n, 0);

  vector<int> st;
  for (int i = 0; i < n; ++i)
    if (visited[i] == UNVISITED)
      dfs(i, adj, visited, cycle, st);
  
  vector<string> order;
  string city;
  while (cin >> city)
    order.push_back(city);
  for (auto& city : order)
    cout << city << ' ' << (cycle[city_to_i[city]] ? "safe\n" : "trapped\n");
}
