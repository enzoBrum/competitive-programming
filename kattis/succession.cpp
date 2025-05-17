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
  cin >> n >> m;

  vector<vector<int>> adj;
  unordered_map<string, int> s_to_i;
  vector<string> i_to_s;
  
  string king;
  cin >> king;

  s_to_i[king] = 0;
  adj.push_back({});
  i_to_s.push_back(king);
  vector<int> degree;
  degree.push_back(0);

  while (n--) {
    string child, p1, p2;
    cin >> child >> p1 >> p2;

    if (!s_to_i.contains(child)) {
      s_to_i[child] = s_to_i.size();
      i_to_s.push_back(child);
      adj.push_back({});
      degree.push_back(0);
    }
    if (!s_to_i.contains(p1)) {
      s_to_i[p1] = s_to_i.size();
      i_to_s.push_back(p1);
      adj.push_back({});
      degree.push_back(0);
    }
    if (!s_to_i.contains(p2)) {
      s_to_i[p2] = s_to_i.size();
      i_to_s.push_back(p2);
      adj.push_back({});
      degree.push_back(0);
    }
    
    int c = s_to_i[child], ip1 = s_to_i[p1], ip2 = s_to_i[p2];
    adj[ip1].push_back(c), adj[ip2].push_back(c);
    degree[c] += 2;
  }
  
  unordered_set<string> claims;
  while (m--) {
    string s;
    cin >> s;
    claims.insert(s);
  }
  
  vector<ll> blood(adj.size());
  blood[0] = INT64_MAX;
  
  queue<int> q;
  for (int u = 0; u < adj.size(); ++u)
    if (!degree[u])
      q.push(u);

  while (!q.empty()) {
    auto u = q.front();q.pop();
    
    for (auto& v : adj[u]) {
      degree[v]--;
      blood[v] += (blood[u]/2);
      if (!degree[v])
        q.push(v);
    }
  }
  
  ll gblood = -1;
  string ans;
  for (int u = 1; u < adj.size(); ++u)
    if (blood[u] > gblood && claims.contains(i_to_s[u]))
      ans = i_to_s[u], gblood = blood[u];
  cout << ans << endl;
}
