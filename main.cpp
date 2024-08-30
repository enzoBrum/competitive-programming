#include <bits/stdc++.h>

using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;
using pli = pair<ll, int>;


ll dfs(int u, ll power, vector<vector<pli>>& adj) {
  ll ret = power;

  for (auto&[p, v] : adj[u])
    ret = max(ret, dfs(v, power + p, adj));
  return ret;
}


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  int n;
  cin >> n;

  vector<pair<string, ll>> vec(n);
  for (auto&[s, p] : vec)
    cin >> s >> p;
  sort(vec.begin(), vec.end());
  
  vector<vector<pair<ll, int>>> adj(n);
  vector<int> in_degree(n);
  
  for (int i = 0; i < n; ++i) {
    for (int j = i+1; j < n; ++j) {
      if (vec[j].first.size() <= vec[i].first.size())
        break;
      
      bool proper = true;
      for (int k = 0; k < vec[i].first.size(); ++k)
        proper = proper && vec[i].first[k] == vec[j].first[k];

      if (proper) {
        adj[i].push_back({vec[j].second, j});
        in_degree[j]++;
      }
    }
  }

  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (in_degree[i])
      continue;

    ans = max(ans, dfs(i, vec[i].second, adj));
  }
  
  cout << ans << '\n';
}
