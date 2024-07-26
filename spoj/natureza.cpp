#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using ll = long long;
using ull = unsigned long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int c, r;
  while (cin >> c >> r && c) {
    unordered_map<string, int> mp;
    vector<vector<int>> adj(c);
    while (c--) {
      string animal;
      cin >> animal;
      mp[animal] = mp.size();
    }

    while (r--) {
      string a, b;
      cin >> a >> b;

      int ia = mp[a], ib = mp[b];
      adj[ia].push_back(ib);
      adj[ib].push_back(ia);
    }

    int ans = 1;
    vector<bool> visited(adj.size(), false);
    for (int i = 0; i < adj.size(); ++i) {
      if (visited[i])
        continue;
      queue<int> q;
      q.push(i);
      int cur = 1;
      visited[i] = true;

      while (!q.empty()) {
        auto u = q.front();
        q.pop();

        for (auto &v : adj[u]) {
          if (visited[v])
            continue;
          cur++;
          visited[v] = true;
          q.push(v);
        }
      }

      ans = max(ans, cur);
    }

    cout << ans << '\n';
  }
}
